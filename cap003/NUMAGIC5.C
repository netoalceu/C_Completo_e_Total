/* N£mero m gico programa #5. */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  int magic;
  int guess;

  magic = rand(); /* gera o n£mero m gico */

  printf("Advinhe o n£mero m gico: ");
  scanf("%d", &guess);

  if(guess == magic) {
    printf("** Certo **");
    printf("%d ‚ o n£mero m gico", magic);
  }
  else
    guess > magic ? printf("Alto") : printf("Baixo");
}
