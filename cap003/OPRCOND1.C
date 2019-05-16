#include <stdio.h>

void main(void)
{
  int isqrd, i;

  printf("Digite um n£mero: ");
  scanf("%d", &i);

  isqrd = i>0 ? i*i : -(i*i);

  printf("%d ao quadrado ‚ %d", i, isqrd);
}
