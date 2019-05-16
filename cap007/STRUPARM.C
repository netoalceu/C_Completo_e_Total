#include <stdio.h>

/* Define um tipo de estrutura. */
struct struct_type {
  int a, b;
  char ch;
} ;

void f1(struct struct_type parm);

void main(void)
{
  struct struct_type arg;

  arg.a = 1000;

  f1(arg);
}

void f1(struct struct_type parm)
{
  printf("%d", parm.a);
}
