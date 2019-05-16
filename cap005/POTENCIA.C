/* Apresenta as potˆncias dos n£meros de 1 a 10.
   Nota: muito embora esse programa esteja correto, alguns
   compiladores apresentarao uma mensagem de advertˆncia
   com rela‡ao aos argumentos para as fun‡oes table() e show().
   Se isso acontecer, ignore. */

#include "stdio.h"
#include "stdlib.h"

int pwr(int a, int b);
void table(int p[4][10]);
void show(int p[4][10]);

void main(void)
{
  int *p;

  p = malloc(40*sizeof(int));
  if(!p) {
    printf("falha na solicita‡ao de mem¢ria\n");
    exit(1);
  }
  /* aqui, p ‚ simplesmente um ponteiro */
  table(p);
  show(p);
}

/* Constr¢i a tabela de potˆncias */
void table(int p[4][10]) /* agora o compilador tem uma matriz
                            para trabalhar */
{
  register int i, j;

  for(j=1; j<11; j++)
    for(i=1; i<5; i++) p[i-1][j-1] = pwr(j, i);
}

/* Exibe a tabela de potˆncias inteiras */
void show(int p[4][10]) /* agora o compilador tem uma matriz
                           para trabalhar */
{
  register int i, j;
  printf("%10s %10s %10s %10s\n",
         "N", "N^2", "N^3", "N^4");
  for(j=1; j<11; j++) {
    for(i=1; i<5; i++) printf("%10d ", p[i-1][j-1]);
    printf("\n");
  }
}

/* Eleva um inteiro a uma potˆncia especificada. */
pwr(int a, int b)
{
  register int t=1;
  for(; b; b--) t = t*a;
  return t;
}
