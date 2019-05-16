#include <stdlib.h>
#include <stdio.h>

void main(void)
{
  char p[20];

  ltoa(1423L, p, 16);

  printf(p);
}
