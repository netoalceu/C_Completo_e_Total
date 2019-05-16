/* Encontra as chaves usando uma pesquisa de profundidade primeiro */
#include <stdio.h>
#include <string.h>

#define MAX 100

/* Estrutura  do banco de dados das chaves */
struct FL {
  char from[20];
  char to[20];
  char skip;
};

struct FL keys[MAX]; /* matriz de estruturas do banco de dados */

int f_pos=0; /* n£mero de c“modos na casa */
int find_pos=0; /* ¡ndice do bd de busca */

int tos=0; /* topo da pilha */
struct stack {
  char from[20];
  char to[20];
};
struct stack bt_stack[MAX];  /* pilha de retorno */

void setup(void), route(void);
void assert_keys(char *from, char *to);
void push(char *from, char *to);
void pop(char *from, char *to);
void iskeys(char *from, char *to);
int find(char *from, char *anywhere);
int match(char *from, char *to);

void main(void)
{
  setup();
  iskeys("porta principal", "chaves");
  route();
}

void setup(void)
{
  assert_keys("porta principal", "sala");
  assert_keys("sala", "banheiro");
  assert_keys("sala", "corredor");
  assert_keys("corredor", "dormit¢rio 1");
  assert_keys("corredor", "dormit¢rio 2");
  assert_keys("corredor", "lavabo");
  assert_keys("sala", "cozinha");
  assert_keys("cozinha", "chaves");
}

/* Coloca os fatos no banco de dados */
void assert_keys(char *from, char *to)
{
  if(f_pos<MAX) {
    strcpy(keys[f_pos].from, from);
    strcpy(keys[f_pos].to, to);
    keys[f_pos].skip = 0;
    f_pos++;
  }
  else printf("Banco de dados das chaves cheio.\n");
}

/* Mostra a rota das chaves */
void route(void)
{
  int t;

  t = 0;
  while(t<tos) {
    printf("%s", bt_stack[t].from);
    t++;
    if(t<tos) printf(" para ");
  }
  printf("\n");
}

match(char *from, char *to)
{
  register int t;

  for(t=f_pos; t>-1; t--)
    if(!strcmp(keys[t].from, from) &&
       !strcmp(keys[t].to, to)) return 1;

  return 0; /* nao encontrou */
}

/* Dado from, encontre anywhere */
find(char *from, char *anywhere)
{
  find_pos = 0;
  while(find_pos<f_pos) {
    if(!strcmp(keys[find_pos].from, from) &&
     !keys[find_pos].skip) {
       strcpy(anywhere, keys[find_pos].to);
       keys[find_pos].skip = 1;
       return 1;
    }
    find_pos++;
  }
  return 0;
}

/* Determina se h  uma rota entre from e to */
void iskeys(char *from, char *to)
{
  char anywhere[20];

  if(match(from, to)) {
    push(from, to); /* distƒncia */
    return;
  }

  if(find(from, anywhere)) {
    push(from, to);
    iskeys(anywhere, to);
  }
  else if(tos>0) {
    pop(from, to);
    iskeys(from, to);
  }
}

/* rotinas de pilha */
void push(char *from, char *to)
{
  if(tos<MAX) {
    strcpy(bt_stack[tos].from, from);
    strcpy(bt_stack[tos].to, to);
    tos++;
  }
  else printf("Pilha cheia\n");
}

void pop(char *from, char *to)
{
  if(tos>0) {
    tos--;
    strcpy(from, bt_stack[tos].from);
    strcpy(to, bt_stack[tos].to);
  }
  else printf("Pilha vazia\n");
}
