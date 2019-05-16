#include <string.h>
#include <stdio.h>

void main(void)
{
  char *p;

  p = strstr("isto ‚ um teste", "to");
  printf(p);
}
