#include <stdio.h>
#include <string.h>

void main(void)
{
  char *p;

  p = strchr("isto ‚ um teste", ' ');
  printf(p);
}
