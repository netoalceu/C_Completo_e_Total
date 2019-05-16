#include <stdio.h>
#include <string.h>

void main(void)
{
  char *p;

  p=strtok("O soldado de verao, o patriota da luz do dia", " ");
  printf(p);
  do {
    p = strtok('\0', ", ");
    if(p) printf("|%s", p);
  } while (p);
}
