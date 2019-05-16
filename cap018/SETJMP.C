#include "setjmp.h"
#include "stdio.h"

jmp_buf ebuf;
void f2(void);

void main(void)
{
  char first=1;
  int i;

  printf("1 ");
  i = setjmp(ebuf);
  if(first) {
    first = !first;
    f2();
    printf("Isto nao ser  exibido.");
  }
  printf("%d", i);
}

void f2(void)
{
  printf("2 ");
  longjmp(ebuf, 3);
}
