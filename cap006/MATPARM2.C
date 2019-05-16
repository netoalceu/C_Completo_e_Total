/* Imprime alguns n£meros */
#include <stdio.h>

void display(int num);

void main(void)
{
  int t[10], i;

  for(i=0; i<10; ++i) t[i]=i;
  for(i=0; i<10; i++) display(t[i]);
}

void display(int num)
{
  printf("%d ", num);
}

