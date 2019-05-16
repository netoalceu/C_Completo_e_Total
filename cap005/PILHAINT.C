#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void push(int i);
int pop(void);

int *tos, *p1, stack[SIZE];

void main(void)
{
  int value;

  tos = stack; /* faz tos conter o topo da pilha */
  p1 = stack; /* inicializa p1 */

  do {
    printf("Entre com o valor: ");
    scanf("%d", &value);
    if(value!=0) push(value);
    else printf("valor do topo ‚ %d\n", pop());
  } while(value!=-1);
}

void push(int i)
{
  p1++;
  if(p1==(tos+SIZE)) {
    printf("estouro da pilha");
    exit(1);
  }
  *p1 = i;
}

pop(void)
{
  if(p1==tos) {
    printf("pilha vazia");
    exit(1);
  }
  p1--;
  return *(p1+1);
}
