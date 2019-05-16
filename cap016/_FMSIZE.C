#include <malloc.h>
#include <stdio.h>

struct addr {
  char name[40];
  char street[40];
  char city[40];
  char state[3];
  char zip[10];
};

void main(void)
{
  struct addr __far *p;

  p = _fmalloc(sizeof(struct addr));

  printf("tamanho do bloco ‚ %u", _fmsize(p));
}
