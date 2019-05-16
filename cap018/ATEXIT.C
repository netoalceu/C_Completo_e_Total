#include <stdlib.h>
#include <stdio.h>

void done(void);

void main(void)
{
  if(atexit(done)) printf("Erro em atexit().");
}

void done(void)
{
  printf("Al“ a¡");
}
