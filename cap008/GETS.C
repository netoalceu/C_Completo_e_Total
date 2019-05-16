#include <stdio.h>
#include <string.h>

void main(void)
{
  char str[80];

  gets(str);
  printf("O comprimento ‚ %d", strlen(str));
}
