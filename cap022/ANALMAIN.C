/* Programa de demonstra‡ao do analisador */
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char *prog;
void eval_exp(double *answer);

void main(void)
{
  double answer;
  char *p;

  p = malloc(100);
  if(!p) {
    printf("Falha de aloca‡„o.\n");
    exit(1);
  }

  /* Processa express”es at‚ que uma linha em branco seja
     digitada.
  */
  do {
    prog = p;
    printf("Digite uma express„o: ");
    gets(prog);
    if(!*prog) break;
    eval_exp(&answer);
    printf("A resposta ‚: %.2f\n", answer);
  } while(*p);
}
