#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void insert(char *item, int count);

void main(void)
{
  char s[80];

  printf("Digite uma string: ");
  gets(s);
  insert(s, strlen(s));
  printf("A string ordenada: %s\n", s);
}

void insert(char *item, int count)
{
  register int a, b;
  char t;

  for(a=1; a<count; ++a) {
    t = item[a];
    for(b=a-1; b>=0 && t<item[b]; b--)
      item[b+1] = item[b];
    item[b+1] = t;
  }
}
