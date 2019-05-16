#include <stdio.h>

void main(void)
{
  struct {
    int a;
    int b;
  } x, y;

  x.a = 10;

  y = x; /* atribui uma estrutura a outra */

  printf("%d", y.a);
}
