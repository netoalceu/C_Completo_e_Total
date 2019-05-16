/****** Fun‡oes da biblioteca interna ******/

/* Adicione mais por conta pr¢pria aqui. */

#include <conio.h> /* elimine isto se seu
                      compilador nao suporta
                      este arquivo de cabe‡alho */

#include <stdio.h>
#include <stdlib.h>

extern char *prog; /* aponta para a posi‡ao corrente no programa */
extern char token[80]; /* mant‚m a representa‡ao string do token */
extern char token_type; /* cont‚m o tipo do token */
extern char tok; /* mant‚m a representa‡ao interna do token */

enum tok_types {DELIMITER, IDENTIFIER, NUMBER, KEYWORD, TEMP,
                STRING, BLOCK};

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

int get_token(void);
void sntx_err(int error), eval_exp(int *result);
void putback(void);

/* Obt‚m um caractere do console. (Use getchar()
   se seu compilador nao suportar getche().) */
call_getche()
{
  char ch;
  ch = getche();
  while (*prog!=')') prog++;
  prog++;   /* avan‡a at‚ o fim da linha */
  return ch;
}

/* Exibe um caractere na tela. */
call_putch()
{
  int value;

  eval_exp(&value);
  printf("%c", value);
  return value;
}

/* Chama puts(). */
call_puts(void)
{
  get_token();
  if(*token!='(') sntx_err(PAREN_EXPECTED);
  get_token();
  if(token_type!=STRING) sntx_err(QUOTE_EXPECTED);
  puts(token);
  get_token();
  if(*token!=')') sntx_err(PAREN_EXPECTED);

  get_token();
  if(*token!=';') sntx_err(SEMI_EXPECTED);
  putback();
  return 0;
}

/* Uma fun‡ao embutida de sa¡da para o console. */
int print(void)
{
  int i;

  get_token();
  if(*token!='(')  sntx_err(PAREN_EXPECTED);

  get_token();
  if(token_type==STRING) { /* exibe uma string */
    printf("%s ", token);
  }
  else {  /* exibe um n£mero */
    putback();
    eval_exp(&i);
    printf("%d ", i);
  }

  get_token();

  if(*token!=')') sntx_err(PAREN_EXPECTED);

  get_token();
  if(*token!=';') sntx_err(SEMI_EXPECTED);
  putback();
  return 0;
}

/* Lˆ um inteiro do teclado. */
getnum(void)
{
  char s[80];

  gets(s);
  while(*prog!=')') prog++;
  prog++;  /* avan‡a at‚ o fim da linha */
  return atoi(s);
}

