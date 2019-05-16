#include <stdio.h>
#include <string.h>

char *p="al“ mundo";

void main(void)
{
  register int t;

  /* imprime o conte£do da string normal e de tr s para frente */
  printf(p);
  for(t=strlen(p)-1; t>-1; t--) printf("%c", p[t]);
}
