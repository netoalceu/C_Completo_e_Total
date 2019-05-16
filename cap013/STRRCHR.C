#include <string.h>
#include <stdio.h>

void main(void)
{
  char *p;

  p = strrchr("isto ‚ um teste", 'o');
  printf(p);
}
