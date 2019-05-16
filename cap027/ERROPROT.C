/* Este programa est  correto. */
#include <stdio.h>

float mul(float a, float b);

void main(void)
{
  float x, y;

  scanf("%f%f", &x, &y);
  printf("%f", mul(x, y));
}

float mul(float a, float b)
{
  return a*b;
}
