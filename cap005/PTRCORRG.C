/* Este programa agora est  correto */
#include "string.h"
#include "stdio.h"

void main(void)
{
  char *p1;
  char s[80];

  do {
    p1 = s;
    gets(s); /* lˆ uma string */
    /* imprime o equivalente decimal de cada caractere */
    while(*p1) printf(" %d", *p1++);
  } while (strcmp(s, "fim"));
}

