#include <stdio.h>

void main(void)
{
  int i;

  /* mostra uma tabela de quadrados e cubos */
  for(i=1; i<20; i++)
    printf("%8d %8d %8d\n", i, i*i, i*i*i);
}
