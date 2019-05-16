#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  char __far *str;

  if((str = _fmalloc(128))==NULL) {
     printf("erro de aloca‡ao - abortando");
     exit(1);
  }

  /* agora libera a mem¢ria */
  _ffree(str);
}
