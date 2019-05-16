/* Divide o primeiro n£mero pelo segundo. */
#include <stdio.h>

void main(void)
{
  int a, b;

  printf("Digite dois n£meros: ");
  scanf("%d%d", &a, &b);

  if(b) printf("%d\n", a/b);
  else printf("N„o pode dividir por zero\n");
}
