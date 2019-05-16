#include <string.h>
#include <stdio.h>

#define SIZE 80

void main(void)
{
  char buf1[SIZE], buf2[SIZE];

  strcpy(buf1, "Quando, no curso do ...");
  memcpy(buf2, buf1, SIZE);
  printf(buf2);
}
