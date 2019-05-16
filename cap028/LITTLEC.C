/* Um interpretador Little C. */

#include <stdio.h>
#include <setjmp.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FUNC        100
#define NUM_GLOBAL_VARS 100
#define NUM_LOCAL_VARS  200
#define NUM_BLOCK       100
#define ID_LEN          31
#define FUNC_CALLS      31
#define NUM_PARAMS      31
#define PROG_SIZE       10000
#define LOOP_NEST       31

enum tok_types {DELIMITER, IDENTIFIER, NUMBER, KEYWORD, TEMP,
                STRING, BLOCK};

/* adicione outros tokens C aqui */
enum tokens {ARG, CHAR, INT, IF, ELSE, FOR, DO, WHILE,
             SWITCH, RETURN, EOL, FINISHED, END};

/* adicione outros operadores duplos (tais como ->) aqui */
enum double_ops {LT=1, LE, GT, GE, EQ, NE};

/* Estas sao as constantes usadas para chamar sntx_err() quando
   ocorre um erro de sintaxe. Adicione mais se desejar.
   NOTA: SYNTAX ‚ uma mensagem gen‚rica de erro usada quando
   nenhuma outra parece apropriada.
 */
enum error_msg
     {SYNTAX, UNBAL_PARENS, NO_EXP, EQUALS_EXPECTED,
      NOT_VAR, PARAM_ERR, SEMI_EXPECTED,
      UNBAL_BRACES, FUNC_UNDEF, TYPE_EXPECTED,
      NEST_FUNC, RET_NOCALL, PAREN_EXPECTED,
      WHILE_EXPECTED, QUOTE_EXPECTED, NOT_TEMP,
      TOO_MANY_LVARS};

char *prog; /* posi‡ao corrente no c¢digo fonte */
char *p_buf; /* aponta para o in¡cio da
                 rea de carga do programa */
jmp_buf e_buf; /* mant‚m ambiente para longjmp() */

/* Uma matriz destas estruturas manter  a informa‡ao
   associada com as vari veis globais.
*/
struct var_type {
  char var_name[ID_LEN];
  enum variable_type var_type;
  int value;
} global_vars[NUM_GLOBAL_VARS];

struct var_type local_var_stack[NUM_LOCAL_VARS];

struct func_type {
  char func_name[ID_LEN];
  char *loc; /* posi‡ao do ponto de entrada da fun‡ao no arquivo */
} func_table[NUM_FUNC];

int call_stack[NUM_FUNC];

struct commands { /* Tabela de busca de palavras reservadas */
  char command[20];
  char tok;
} table[] = { /* Comandos devem ser escritos */
  "if", IF,   /* em min£scula nesta tabela */
  "else", ELSE,
  "for", FOR,
  "do", DO,
  "while", WHILE,
  "char", CHAR,
  "int", INT,
  "return", RETURN,
  "end", END,
  "", END  /* marca fim da tabela */
};

char token[80];
char token_type, tok;

int functos; /* ¡ndice para o topo da pilha de chamadas de fun‡ao */
int func_index; /* ¡ndice na tabela de fun‡oes */
int gvar_index; /* ¡ndice na tabela global de vari veis */
int lvartos; /* ¡ndice para a pilha de vari veis locais */

int ret_value; /* valor de retorno de fun‡ao */

void print(void), prescan(void);
void decl_global(void), call(void), putback(void);
void decl_local(void), local_push(struct var_type i);
void eval_exp(int *value), sntx_err(int error);
void exec_if(void), find_eob(void), exec_for(void);
void get_params(void), get_args(void);
void exec_while(void), func_push(int i), exec_do(void);
void assign_var(char *var_name, int value);
int load_program(char *p, char *fname), find_var(char *s);
void interp_block(void), func_ret(void);
int func_pop(void), is_var(char *s), get_token(void);

char *find_func(char *name);

main(int argc, char *argv[])
{
  if(argc!=2) {
    printf("Uso: littlec <nome_de_arquivo>\n");
    exit(1);
  }

  /* aloca mem¢ria para o programa */
  if((p_buf=(char *) malloc(PROG_SIZE))==NULL) {
    printf("Falha de aloca‡ao");
    exit(1);
  }

  /* carrega o programa a executar */
  if(!load_program(p_buf, argv[1])) exit(1);

  if(setjmp(e_buf)) exit(1); /* inicializa buffer de longjmp */

  /* define apontador de programa para o in¡cio do buffer */
  prog = p_buf;
  prescan(); /* procura a posi‡ao de todas as fun‡oes
                e vari veis globais no programa */
  gvar_index = 0;  /* inicializa ¡ndice de vari veis globais */
  lvartos = 0;     /* inicializa ¡ndice da pilha de vari veis locais */
  functos = 0;     /* inicializa o ¡ndice da pilha de CALL */

/* prepara chamada de main */
  prog = find_func("main"); /* acha o ponto de in¡cio do programa */
  prog--; /* volta para { inicial */
  strcpy(token, "main");
  call();  /* inicia interpreta‡ao */
  return 0;
}

/* Interpreta um £nico comando ou bloco de c¢digo. Quando
   interp_block() retorna da sua chamada inicial, a chave
   final (ou um return) foi encontrada em main().
*/
void interp_block(void)
{
  int value;
  char block = 0;

  do {
    token_type = get_token();

    /* Se interpretando um £nico comando,
       retorne ao achar o primeiro ponto e v¡rgula
    */

    /* Veja que tipo de token est  pronto */
    if(token_type==IDENTIFIER) {
      /* Nao ‚ uma palavra reservada, logo processa expressao. */
      putback(); /* devolve token para a entrada para
                    posterior processamento por eval_exp() */
      eval_exp(&value);
      if(*token!=';') sntx_err(SEMI_EXPECTED);
    }
    else if(token_type==BLOCK) { /* se delimitador de bloco */
      if(*token=='{') /* ‚ um bloco */
        block = 1; /* intepretando bloco, nao comando */
      else return;
    }
    else /* ‚ palavra reservada */
      switch(tok) {
        case CHAR:
        case INT:       /* declara vari veis locais */
          putback();
          decl_local();
          break;
        case RETURN:    /* retorna da chamada de fun‡ao */
          func_ret();
          return;
        case IF:        /* processa um comando if */
          exec_if();
          break;
        case ELSE:      /* processa um comando else */
          find_eob();   /* acha fim do bloco de else
                           e continua execu‡ao */
          break;
        case WHILE:     /* processa uma repeti‡ao while */
          exec_while();
          break;
        case DO:        /* processa uma repeti‡ao do-while */
          exec_do();
          break;
        case FOR:       /* processa uma repeti‡ao for */
          exec_for();
          break;
        case END:
          exit(0);
      }
  } while (tok != FINISHED && block);
}

/* Carrega um programa. */
load_program(char *p, char *fname)
{
  FILE *fp;
  int i=0;

  if((fp=fopen(fname, "rb"))==NULL) return 0;

  i = 0;
  do {
    *p = getc(fp);
    p++; i++;
  } while(!feof(fp) && i<PROG_SIZE);
  if(*(p-2)==0x1a) *(p-2) = '\0'; /* encerra o programa com nulo */
  else *(p-1) = '\0';
  fclose(fp);
  return 1;
}

/* Acha a posi‡ao de todas as fun‡oes no programa
   e armazena todas as vari veis globais. */
void prescan(void)
{
  char *p;
  char temp[32];
  int brace = 0; /* Quando 0, esta vari vel n¢s indica que a
                    posi‡ao corrente no c¢digo fonte est  fora
                    de qualquer fun‡ao. */

  p = prog;
  func_index = 0;
  do {
    while(brace) {  /* deixa de lado o c¢digo dentro das fun‡oes */
      get_token();
      if(*token=='{') brace++;
      if(*token=='}') brace--;
    }

    get_token();

    if(tok==CHAR || tok==INT) { /* ‚ uma vari vel global */
      putback();
      decl_global();
    }
    else if(token_type==IDENTIFIER) {
       strcpy(temp, token);
       get_token();
       if(*token=='(') { /* t‚m que ser uma fun‡ao */
         func_table[func_index].loc = prog;
         strcpy(func_table[func_index].func_name, temp);
         func_index++;
         while(*prog!=')') prog++;
         prog++;
         /* agora prog aponta para o abre chaves da fun‡ao */
       }
       else
         putback();
    }
    else if(*token=='{') brace++;
  } while(tok!=FINISHED);
  prog = p;
}

char *find_func(char *name)
{
  register int i;

  for(i=0; i<func_index; i++)
    if(!strcmp(name, func_table[i].func_name))
      return func_table[i].loc;

  return NULL;
}

/* Declara uma vari vel global. */
void decl_global(void)
{
  get_token();  /* obt‚m o tipo */
  global_vars[gvar_index].var_type = tok;
  global_vars[gvar_index].value = 0; /* inicializa com 0 */

  do { /* processa lista separada por v¡rgulas */
    get_token();  /* obt‚m nome */
    strcpy(global_vars[gvar_index].var_name, token);
    get_token();
    gvar_index++;
  } while(*token==',');
  if(*token!=';') sntx_err(SEMI_EXPECTED);
}

/* Declara uma vari vel local. */
void decl_local(void)
{
  struct var_type i;

  get_token();  /* obt‚m tipo */

  i.var_type = tok;
  i.value = 0;  /* inicializa com 0 */

  do { /* processa lista separada por v¡rgulas */
    get_token();  /* obt‚m nome da vari vel */
    strcpy(i.var_name, token);
    local_push(i);
    get_token();
    gvar_index++;
  } while(*token==',');
  if(*token!=';') sntx_err(SEMI_EXPECTED);
}

/* Chama una fun‡ao. */
void call(void)
{
  char *loc, *temp;
  int lvartemp;

  loc = find_func(token); /* encontra ponto de entrada da fun‡ao */
  if(loc==NULL)
    sntx_err(FUNC_UNDEF); /* fun‡ao nao definida */
  else {
    lvartemp = lvartos;  /* guarda ¡ndice da pilha de var locais */
    get_args();  /* obt‚m argumentos da fun‡ao */
    temp = prog; /* salva endere‡o de retorno */
    func_push(lvartemp); /* salva ¡ndice da pilha de var locais */
    prog = loc;  /* redefine prog para o in¡cio da fun‡ao */
    get_params(); /* carrega os parƒmetros da fun‡ao com
                     os valores dos argumentos */
    interp_block(); /* interpreta a fun‡ao */
    prog = temp; /* redefine o apontador de programa */
    lvartos = func_pop(); /* redefine a pilha de var locais */
  }
}

/* Empilha os argumentos de uma fun‡ao na pilha de vari veis
   locais. */
void get_args(void)
{
  int value, count, temp[NUM_PARAMS];
  struct var_type i;

  count = 0;
  get_token();
  if(*token!='(') sntx_err(PAREN_EXPECTED);

  /* processa uma lista de valores separados por v¡rgulas */
  do {
    eval_exp(&value);
    temp[count] = value;
    get_token();
    count++;
  }while(*token==',');
  count--;
  /* agora, empilha em local_var_stack na ordem invertida */
  for(; count>=0; count--) {
    i.value = temp[count];
    i.var_type = ARG;
    local_push(i);
  }
}

/* Obt‚m parƒmetros da fun‡ao. */
void get_params(void)
{
  struct var_type *p;
  int i;

  i=lvartos-1;
  do { /* processa lista de parƒmetros separados por v¡rgulas */
    get_token();
    p = &local_var_stack[i];
    if(*token!=')') {
      if(tok!=INT && tok != CHAR) sntx_err(TYPE_EXPECTED);
      p->var_type = token_type;
      get_token();

      /* liga nome do parƒmetro com argumento que j  est  na
         pilha de vari veis locais */
      strcpy(p->var_name, token);
      get_token();
      i--;
    }
    else break;
  } while(*token==',');
  if(*token!=')') sntx_err(PAREN_EXPECTED);
}

/* Retorna de uma fun‡ao. */
void func_ret(void)
{
  int value;

  value = 0;
  /* obt‚m valor de retorno, se houver */
  eval_exp(&value);

  ret_value = value;
}

/* Empilha uma vari vel local. */
void local_push(struct var_type i)
{
  if(lvartos>NUM_LOCAL_VARS)
    sntx_err(TOO_MANY_LVARS);

  local_var_stack[lvartos] = i;
  lvartos++;
}

/* Desempilha ¡ndice na pilha de vari veis locais */
func_pop(void)
{
  functos--;
  if(functos<0) sntx_err(RET_NOCALL);
  return(call_stack[functos]);
}

/* Empilha ¡ndice da pilha de vari veis locais */
void func_push(int i)
{
  if(functos>NUM_FUNC)
    sntx_err(NEST_FUNC);
  call_stack[functos] = i;
  functos++;
}

/* Atribui um valor a uma vari vel. */
void assign_var(char *var_name, int value)
{
  register int i;

  /* primeiro, veja se ‚ uma vari vel local */
  for (i=lvartos-1; i>=call_stack[functos-1]; i--)  {
    if(!strcmp(local_var_stack[i].var_name, var_name)) {
      local_var_stack[i].value = value;
      return;
    }
  }
  if(i < call_stack[functos-1])
  /* se nao ‚ local, tente na tabela de vari veis globais */
    for(i=0; i<NUM_GLOBAL_VARS; i++)
      if(!strcmp(global_vars[i].var_name, var_name)) {
        global_vars[i].value = value;
        return;
      }
  sntx_err(NOT_VAR); /* vari vel nao encontrada */
}

/* Encontra o valor de uma vari vel. */
int find_var(char *s)
{
  register int i;

   /* primeiro, veja se ‚ uma vari vel local */
  for (i=lvartos-1; i>=call_stack[functos-1]; i--)
    if(!strcmp(local_var_stack[i].var_name, token))
      return local_var_stack[i].value;

  /* se nao ‚ local, tente na tabela de vari veis globais */
  for(i=0; i<NUM_GLOBAL_VARS; i++)
    if(!strcmp(global_vars[i].var_name, s))
      return global_vars[i].value;

  sntx_err(NOT_VAR); /* vari vel nao encontrada */
}

/* Determina se um identificador ‚ uma vari vel.
   Retorna 1 se a vari vel ‚ encontrada, 0 caso contr rio.
*/
int is_var(char *s)
{
  register int i;

  /* primeiro, veja se ‚ uma vari vel local */
  for (i=lvartos-1; i>=call_stack[functos-1]; i--)
    if(!strcmp(local_var_stack[i].var_name, token))
      return 1;

  /* caso contr rio, tente com as vari veis globais */
  for(i=0; i<NUM_GLOBAL_VARS; i++)
    if(!strcmp(global_vars[i].var_name, s))
      return 1;

  return 0;
}

/* Executa um comando if. */
void exec_if(void)
{
  int cond;

  eval_exp(&cond); /* obt‚m expressao esquerda */

  if(cond) { /* ‚ verdadeira, portanto processa alvo do IF */
    interp_block();
  }
  else { /* caso contr rio ignore o bloco de IF e
            processe o ELSE, se existir */
    find_eob();
    get_token();

    if(tok!=ELSE) {
      putback(); /* devolve o token se nao ‚ ELSE */
      return;
    }
    interp_block();
  }
}

/* Executa uma repeti‡ao while. */
void exec_while(void)
{
  int cond;
  char *temp;

  putback();
  temp = prog;  /* salva posi‡ao do in¡cio da repeti‡ao while */
  get_token();
  eval_exp(&cond);  /* verifica a expressao condicional */
  if(cond) interp_block();  /* se verdadeira, interpreta */
  else {  /* caso contr rio, ignore a repeti‡ao */
    find_eob();
    return;
  }
  prog = temp; /* volta para o in¡cio da repeti‡ao */
}

/* Executa uma repeti‡ao do. */
void exec_do(void)
{
  int cond;
  char *temp;

  putback();
  temp = prog; /* salva posi‡ao do in¡cio da repeti‡ao do */

  get_token(); /* obt‚m in¡cio da repeti‡ao */
  interp_block(); /* interpreta a repeti‡ao */
  get_token();
  if(tok!=WHILE) sntx_err(WHILE_EXPECTED);
  eval_exp(&cond); /* verifica a condi‡ao da repeti‡ao */
  if(cond) prog = temp; /* se verdadeiro, repete;
                           caso contr rio, continua */
}

/* Acha o fim de um bloco. */
void find_eob(void)
{
  int brace;

  get_token();
  brace = 1;
  do {
    get_token();
    if(*token=='{') brace++;
    else if(*token=='}') brace--;
  } while(brace);
}

/* Executa uma repeti‡ao for. */
void exec_for(void)
{
  int cond;
  char *temp, *temp2;
  int brace ;

  get_token();
  eval_exp(&cond);  /* inicializa a expressao */
  if(*token!=';') sntx_err(SEMI_EXPECTED);
  prog++; /* passa do ; */
  temp = prog;
  for(;;) {
    eval_exp(&cond);  /* verifica a condi‡ao */
    if(*token!=';') sntx_err(SEMI_EXPECTED);
    prog++; /* passa do ; */
    temp2 = prog;

    /* acha o in¡cio do bloco do for */
    brace = 1;
    while(brace) {
      get_token();
      if(*token=='(') brace++;
      if(*token==')') brace--;
    }

    if(cond) interp_block();  /* se verdadeiro, interpreta */
    else {  /* caso contr rio, ignora a repeti‡ao */
      find_eob();
      return;
    }
    prog = temp2;
    eval_exp(&cond); /* efetua o incremento */
    prog = temp; /* volta para o in¡cio */
  }
}

