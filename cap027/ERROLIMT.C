#include <stdio.h>

void main(void)
{
  int var1;
  char s[10];
  int var2;

  var1 = 10;  var2=10;
  gets(s);
  printf("%s %d %d", s, var1, var2);
}
