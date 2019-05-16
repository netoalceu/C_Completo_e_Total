#include <stdio.h>

void main(void)
{
  /* Isto escreve "isso e um teste" justificado a esquerda
     em um campo de 20 caracteres.
  */
  printf("%-20s", "isso e um teste");

  /* Isto escreve um float com 3 casas decimais em um campo
     de 10 caracteres. O resultado sera "    12.234".
  */
  printf("%10.3f", 12.234657);
}
