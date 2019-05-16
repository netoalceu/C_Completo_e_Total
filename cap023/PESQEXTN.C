/* Pesquisa de extens„o primeiro */
#include <stdio.h>
#include <string.h>

#define MAX 100

/* estrutura do banco de dados sobre os v“os */
struct FL {
  char from[20]; /* de */
  char to[20]; /* para */
  int distance;
  char skip; /* usado no retorno */
};

struct FL flight[MAX]; /* matriz de estruturas do banco de dados */

int f_pos=0; /* n£mero de entradas do b.d. dos v“os */
int find_pos=0; /* ¡ndice de pesquisa no b.d. dos v“os */
int tos=0; /* topo da pilha */
struct stack {
  char from[20];
  char to[20];
  int dist;
};
struct stack bt_stack[MAX];  /* pilha de retorno */

void setup(void), route(char *to);
void route(char *to);
void assert_flight(char *from, char *to, int dist);
void push(char *from, char *to, int dist);
void pop(char *from, char *to, int *dist);
void isflight(char *from, char *to);
int find(char *from, char *anywhere);
int match(char *from, char *to);

void main(void)
{
  char from[20], to[20];

  setup();

  printf("De? ");
  gets(from);
  printf("Para? ");
  gets(to);

  isflight(from, to);
  route(to);
}

void setup(void)
{
  assert_flight("New York", "Chicago", 1000);
  assert_flight("Chicago", "Denver", 1000);
  assert_flight("New York", "Toronto",800);
  assert_flight("New York", "Denver", 1900);
  assert_flight("Toronto", "Calgary", 1500);
  assert_flight("Toronto", "Los Angeles", 1800);
  assert_flight("Toronto", "Chicago", 500);
  assert_flight("Denver", "Urbana", 1000);
  assert_flight("Denver", "Houston", 1500);
  assert_flight("Houston", "Los Angeles", 1500);
  assert_flight("Denver", "Los Angeles", 1000);
}

/* Coloca os fatos no banco de dados */
void assert_flight(char *from, char *to, int dist)
{
  if(f_pos<MAX) {
    strcpy(flight[f_pos].from, from);
    strcpy(flight[f_pos].to, to);
    flight[f_pos].distance = dist;
    flight[f_pos].skip = 0;
    f_pos++;
  }
  else printf("Banco de dados de v“os cheio.\n");
}

/* Mostra a rota e a distƒncia total */
void route(char *to)
{
  int dist, t;

  dist = 0;
  t = 0;
  while(t<tos) {
    printf("%s para ", bt_stack[t].from);
    dist += bt_stack[t].dist;
    t++;
  }
  printf("%s\n", to);
  printf("A distancia ‚: %d\n", dist);
}

/* Se h  o v“o entre from e to, entao devolve a distƒncia
   do v“o; caso contr rio, devolve 0. */
match(char *from, char *to)
{
  register int t;

  for(t=f_pos-1; t>-1; t--)
    if(!strcmp(flight[t].from, from) &&
      !strcmp(flight[t].to, to)) return flight[t].distance;

  return 0; /* n„o encontrou */
}

/* Dado from, encontre anywhere */
find(char *from, char *anywhere)
{
  find_pos = 0;
  while(find_pos<f_pos) {
    if(!strcmp(flight[find_pos].from, from) &&
     !flight[find_pos].skip) {
       strcpy(anywhere, flight[find_pos].to);
       flight[find_pos].skip = 1; /* torna ativo */
       return flight[find_pos].distance;
    }
    find_pos++;
  }
  return 0;
}

void isflight(char *from, char *to)
{
  int d, dist;
  char anywhere[20];

  while(dist=find(from, anywhere)) {
    /* modifica‡ao para extensao primeiro */
    if(d=match(anywhere, to)) {
      push(from, to, dist);
      push(anywhere, to, d);
      return;
    }
  }
  /* tenta outra conexao */
  if(dist=find(from, anywhere)) {
    push(from, to, dist);
    isflight(anywhere, to);
  }
  else if(tos>0) {
    pop(from, to, &dist);
    isflight(from, to);
  }
}

/* rotinas de pilha */
void push(char *from, char *to, int dist)
{
  if(tos<MAX) {
    strcpy(bt_stack[tos].from, from);
    strcpy(bt_stack[tos].to, to);
    bt_stack[tos].dist = dist;
    tos++;
  }
  else printf("Pilha cheia\n");
}

void pop(char *from, char *to, int *dist)
{
  if(tos>0) {
    tos--;
    strcpy(from, bt_stack[tos].from);
    strcpy(to, bt_stack[tos].to);
    *dist = bt_stack[tos].dist;
  }
  else printf("Pilha vazia\n");
}
