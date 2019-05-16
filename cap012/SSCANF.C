#include <stdio.h>

void main(void)
{
  char str[80];
  int i;

  sscanf("Alo 1 2 3 4 5", "%s%d", str, &i);
  printf("%s %d", str, i);
}
