#include <stdio.h>
#include <string.h>

void main(void)
{
  char str[80];

  strcpy(str, "isso ‚ um exemplo");

  puts(str);
}
