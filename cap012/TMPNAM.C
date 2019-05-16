#include <stdio.h>

void main(void)
{
  char name[40];
  int i;

  for(i=0; i<3; i++) {
    tmpnam(name);
    printf("%s ", name);
  }
}
