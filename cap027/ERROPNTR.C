/* Este programa est  correto */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  char *p;

  p = malloc(100); /* esta linha est  errada */

  if(!p) {
    printf("sem mem¢ria\n");
    exit(1);
  }

  gets(p);
  printf(p);
}
