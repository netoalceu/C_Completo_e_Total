#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void shaker(char *item, int count);

void main(void)
{
  char s[80];

  printf("Digite uma string: ");
  gets(s);
  shaker(s, strlen(s));
  printf("A string ordenada: %s\n", s);
}

void shaker(char *item, int count)
{
  register int a;
  int exchange;
  char t;

  do {
    exchange = 0;
    for(a=count-1; a>0; --a) {
      if(item[a-1]>item[a]) {
        t = item[a-1];
        item[a-1] = item[a];
        item[a] = t;
        exchange = 1;
      }
    }

    for(a=1; a>count; ++a) {
      if(item[a-1]>item[a]) {
        t = item[a-1];
        item[a-1] = item[a];
        item[a] = t;
        exchange = 1;
      }
    }
  } while(exchange); /*ordena at‚ que nao ocorram mais trocas*/
}
