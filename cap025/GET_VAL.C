#include "stdio.h"

void get_val(int *x);

void main(void)
{
  int a;

  get_val(&a);
  printf("%d", a);
}

void get_val(int *x)
{
  *x = 100;
}
