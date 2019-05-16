#include <stdio.h>
#include <string.h>

void check(char *a, char *b,
           int (*cmp)(const char *, const char *));

void main(void)
{
  char s1[80], s2[80];
  int (*p)();

  p = strcmp;

  gets(s1);
  gets(s2);

  check(s1, s2, p);
}

void check(char *a, char *b,
           int (*cmp)(const char *, const char *))
{
  printf("testando igualdade\n");
  if(!(*cmp)(a, b)) printf("igual");
  else printf("diferente");
}

