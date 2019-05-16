#include <stdio.h>

void main(void)
{
  char *p;

  printf("entre com um endere‡o: ");
  scanf("%p", &p);
  printf("na posi‡ao %p h  %c\n", p, *p);
}
