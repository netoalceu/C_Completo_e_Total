#include <stdlib.h>
#include <stdio.h>

void main(void)
{
  ldiv_t n;

  n = ldiv(100000L, 3L);

  printf("quociente & resto: %ld %ld\n", n.quot, n.rem);
}
