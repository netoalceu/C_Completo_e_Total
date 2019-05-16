#include <stdio.h>
#include <string.h>

void main(void)
{
  char *p;

  p = memchr("isto ‚ um teste", ' ', 15);
  printf(p);
}
