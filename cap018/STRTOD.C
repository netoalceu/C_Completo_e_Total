#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

void main(void)
{
  char *end, *start="100.00 alicates 200.00 martelos";

  end = start;
  while(*start) {
    printf("%f, ", strtod(start, &end));
    printf("restante: %s\n", end);
    start = end;
    /* pula os nao d¡gitos */
    while(!isdigit(*start) && *start) start++;
  }
}
