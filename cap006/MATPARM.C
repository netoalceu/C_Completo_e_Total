/* Imprime alguns n£meros */
#include <stdio.h>

void display(int num[10]);

void main(void)
{
  int t[10], i;

  for(i=0; i<10; ++i) t[i]=i;
  display(t);
}

void display(int num[10])
{
  int i;

  for(i=0; i<10; i++) printf("%d ", num[i]);
}
