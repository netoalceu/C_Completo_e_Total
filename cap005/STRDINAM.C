/* Aloca espa‡o para uma string dinamicamente, solicita
   a entrada do usu rio e, em seguida, imprime a string de
   t s para frente.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(void)
{
  char *s;
  register int t;

  s = malloc(80);

  if(!s) {
    printf("falha na solicita‡ao de mem¢ria\n");
    exit(1);
  }

  gets(s);
  for(t=strlen(s)-1; t>=0; t--) putchar(s[t]);
  free(s);
}
