#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>

char *alpha =  "abcdefghijklmnopqrstuvwxyz";

int comp(const void *ch, const void *s);

void main(void)
{
  char ch;
  char *p;

  do {
    printf("Digite um caractere: ");
    ch = getche();
    ch = tolower(ch);
    p = (char *)bsearch(&ch, alpha, 26, 1, comp);
    if(p) printf(" est  no alfabeto\n");
    else printf(" n„o est  no alfabeto\n");
  } while(p);
}

/* compara dois caracteres */
comp(const void *ch, const void *s)
{
  return *(char *)ch-*(char *)s;
}
