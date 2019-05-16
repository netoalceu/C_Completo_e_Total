#include <string.h>
#include <stdio.h>

void main(void)
{
  int len;

  len = strspn("isto ‚ um teste", "otsi ");
  printf("%d", len);
}
