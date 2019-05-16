#include <stdlib.h>
#include <stdio.h>

void main(void)
{
  div_t n;

  n = div(10, 3);

  printf("quociente e resto: %d %d\n", n.quot, n.rem);
}
