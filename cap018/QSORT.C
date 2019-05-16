#include <stdlib.h>
#include <stdio.h>

int num[10] = {
  1, 3, 6, 5, 8, 7, 9, 6, 2, 0
};

int comp(const void *, const void *);

void main(void)
{
  int i;

  printf("Matriz original: ");
  for(i=0; i<10; i++) printf("%d ", num[i]);

  qsort(num, 10, sizeof(int), comp);

  printf("\nMatriz ordenada: ");
  for(i=0; i<10; i++) printf("%d ", num[i]);
}

/* compara os inteiro */
comp(const void *i, const void *j)
{
  return *(int *)i - *(int *)j;
}
