#include <stdlib.h>
#include <stdio.h>

void main(void)
{
  char p[20];

  itoa(1423, p, 16);

  printf(p);
}
