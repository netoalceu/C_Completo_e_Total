#include <stdlib.h>
#include <stdio.h>

void main(void)
{
  char num1[80], num2[80];

  printf("Digite o primeiro: ");
  gets(num1);
  printf("Digite o segundo: ");
  gets(num2);
  printf("A soma ‚: %ld", atol(num1) + atol(num2));
}
