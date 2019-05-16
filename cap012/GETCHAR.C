#include <stdio.h>

void main(void)
{
  char s[256], *p;

  p = s;

  while((*p++=getchar())!='\n') ;
  *p = '\0'; /* acrescenta o terminador nulo */
  printf(s);
}
