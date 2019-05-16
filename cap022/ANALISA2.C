/* Este m¢dulo cont‚m um analisador recursivo descendente
   que reconhece vari veis.
*/

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define DELIMITER  1
#define VARIABLE   2
#define NUMBER     3

extern char *prog; /* cont‚m a expressao a ser analisada */
char token[80];
char tok_type;

double vars[26]= {  /* 26 vari veis do usu rio */
  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
  0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

void eval_exp(double *answer), eval_exp2(double *answer);
void eval_exp1(double *answer);
void eval_exp3(double *answer), eval_exp4(double *answer);
void eval_exp5(double *answer);
void eval_exp6(double *answer), atom(double *answer);
void get_token(void), putback(void);
void unary(char o, double *r);
void serror(int error);
double find_var(char *s);
int isdelim(char c);

/* Ponto de entrada do analisador */
void eval_exp(double *answer)
{
  get_token();
  if(!*token) {
    serror(2);
    return;
  }
  eval_exp1(answer);
  if(*token) serror(0); /* £ltimo token deve ser nulo */
}

/* Processa uma atribui‡„o */
void eval_exp1(double *answer)
{
  int slot;
  char ttok_type;
  char temp_token[80];

  if(tok_type==VARIABLE) {
    /* salva token antigo */
    strcpy(temp_token, token);
    ttok_type = tok_type;

    /* calcula o ¡ndice da vari vel */
    slot = toupper(*token)-'A';

    get_token();
    if(*token != '=') {
      putback(); /* devolve token atual */
      /* restaura token antigo - n„o ‚ atribui‡ao */
      strcpy(token, temp_token);
      tok_type = ttok_type;
    }
    else {
      get_token(); /* pega a pr¢xima parte da expressao */
      eval_exp2(answer);
      vars[slot] = *answer;
      return;
    }
  }

  eval_exp2(answer);
}

/* Soma ou subtrai dois termos. */
void eval_exp2(double *answer)
{
  register char op;
  double temp;

  eval_exp3(answer);
  while((op = *token) == '+' || op == '-') {
    get_token();
    eval_exp3(&temp);
    switch(op) {
      case '-':
        *answer = *answer - temp;
        break;
      case '+':
        *answer = *answer +  temp;
        break;
    }
  }
}

/* Multiplica ou divide dois fatores. */
void eval_exp3(double *answer)
{
  register char op;
  double temp;

  eval_exp4(answer);
  while((op = *token) == '*' || op == '/' || op == '%') {
    get_token();
    eval_exp4(&temp);
    switch(op) {
      case '*':
        *answer = *answer * temp;
        break;
      case '/':
        *answer = *answer / temp;
        break;
      case '%':
        *answer = (int) *answer % (int) temp;
        break;
    }
  }
}

/* Processa um expoente */
void eval_exp4(double *answer)
{
  double temp, ex;
  register int t;

  eval_exp5(answer);
  if(*token=='^') {
    get_token();
    eval_exp4(&temp);
    ex = *answer;
    if(temp==0.0) {
      *answer = 1.0;
      return;
    }
    for(t=temp-1; t>0; --t) *answer = (*answer) * (double)ex;
  }
}

/* Avalia um + ou - un rio */
void eval_exp5(double *answer)
{
  register char op;

  op = 0;
  if((tok_type == DELIMITER) && *token=='+' || *token == '-') {
    op = *token;
    get_token();
  }
  eval_exp6(answer);
  if(op=='-')*answer = -(*answer);
}

/* Processa uma expressao entre parˆnteses */
void eval_exp6(double *answer)
{
  if((*token == '(')) {
    get_token();
    eval_exp2(answer);
    if(*token != ')')
      serror(1);
    get_token();
  }
  else
    atom(answer);
}

void atom(double *answer)
{
  switch(tok_type) {
    case VARIABLE:
      *answer = find_var(token);
      get_token();
      return;
    case NUMBER:
      *answer = atof(token);
      get_token();
      return;
    default:
      serror(0);
  }
}

/* Devolve um token … stream de entrada. */
void putback(void)
{
  char *t;

  t = token;
  for(; *t; t++) prog--;
}

/* Apresenta um erro de sintaxe */
void serror(int error)
{
  static char *e[] = {
      "Erro de sintaxe",
      "Falta parˆnteses",
      "Nenhuma express„o presente"

    };
  printf("%s\n", e[error]);
}

/* Devolve o pr¢ximo token. */
void get_token(void)
{

  register char *temp;

  tok_type = 0;
  temp = token;
  *temp = '\0';

  if(!*prog) return; /* final da express„o */

  while(isspace(*prog)) ++prog; /* ignora espa‡os em branco */

  if(strchr("+-*/%^=()", *prog)) {
    tok_type = DELIMITER;
    /* avan‡a para o pr¢ximo char */
    *temp++ = *prog++;
  }
  else if(isalpha(*prog)) {
    while(!isdelim(*prog)) *temp++ = *prog++;
    tok_type = VARIABLE;
  }
  else if(isdigit(*prog)) {
    while(!isdelim(*prog)) *temp++ = *prog++;
    tok_type = NUMBER;
  }

  *temp = '\0';
}

/* Devolve verdadeiro se c ‚ um DELIMITER */
isdelim(char c)
{
  if(strchr(" +-/*%^=()", c) || c==9 || c=='\r' || c==0)
    return 1;
  return 0;
}

double find_var(char *s)
{
  if(!isalpha(*s)) {
    serror(1);
    return 0.0;
  }
  return vars[toupper(*token)-'A'];
}
