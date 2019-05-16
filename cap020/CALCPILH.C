/* Uma calculadora simples de quatro fun‡oes */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int *p;   /* apontar  para uma regiao de mem¢ria livre */
int *tos; /* aponta para o topo da pilha */
int *bos; /* aponta para o fundo da pilha */

void push(int i);
int pop(void);

void main(void)
{
  int a, b;
  char s[80];

  p = (int *) malloc(MAX*sizeof(int)); /*obt‚m mem¢ria da pilha*/
  if(!p) {
    printf("falha de aloca‡ao\n");
    exit(1);
  }
  tos = p;
  bos = p+MAX-1;

  printf("Calculadora de quatro fun‡oes\n");
  printf("Digite 's' para sair\n");

  do {
    printf(": ");
    gets(s);
    switch(*s) {
      case '+':
        a = pop();
        b = pop();
        printf("%d\n", a+b);
        push(a+b);
        break;
      case '-':
        a = pop();
        b = pop();
        printf("%d\n", b-a);
        push(b-a);
        break;
      case '*':
        a = pop();
        b = pop();
        printf("%d\n", b*a);
        push(b*a);
        break;
      case '/':
        a = pop();
        b = pop();
        if(a==0) {
          printf("divisao por 0\n");
          break;
        }
        printf("%d\n", b/a);
        push(b/a);
        break;
      case '.': /* mostra o conte£do do topo da pilha */
        a = pop();
        push(a);
        printf("O valor atual no topo da pilha ‚: %d\n", a);
        break;
      default:
        push(atoi(s));
    }
  } while(*s!='s');
}

/* poe um elemento na pilha */
void push(int i)
{
  if(p>bos) {
    printf("Pilha cheia\n");
    return;
  }
  *p = i;
  p++;
}

/* Recupera o elemento do topo da pilha */
pop(void)
{
  p--;
  if(p<tos) {
    printf("Pilha vazia\n");
    return 0;
  }
  return *p;
}
