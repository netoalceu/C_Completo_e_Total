#include <string.h>
#include <stdio.h>

void main(void)
{
  int len;

  len = strcspn("isto ‚ um teste", "uz");
  printf("%d", len);
}
