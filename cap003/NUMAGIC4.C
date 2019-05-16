/* Programa de n£meros m gicos #4. */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  int magic;  /* n£mero m gico */
  int guess;  /* palpite do usu rio */

  magic = rand();  /* gera o n£mero m gico */

  printf("Adivinhe o n£mero m gico: ");
  scanf("%d", &guess);

  if(guess == magic) {
    printf("** certo **");
    printf("%d ‚ o n£mero m gico", magic);
  }
  else if(guess > magic)
     printf("Errado, muito alto");
  else printf("Errado, muito baixo");
}
