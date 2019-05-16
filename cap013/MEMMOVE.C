#include <stdio.h>
#include <string.h>

#define SIZE 80

void main(void)
{
  char str1[SIZE], str2[SIZE];

  strcpy(str1, "Quando, no curso do ...");
  memmove(str2, str1, SIZE);
  printf(str2);
}
