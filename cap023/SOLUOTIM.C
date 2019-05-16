/* Solu‡ao ¢tima usando menor esfor‡o
   com remo‡ao de percurso
*/
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

struct FL flight[MAX]; /* matriz de estruturas do bd */

int f_pos=0; /* n£mero de entradas do bd dos v“os */
int find_pos=0; /* ¡ndice de pesquisa no bd dos v“os */

int tos=0; /* topo da pilha */
int stos=0; /* topo pilha de solu‡ao */

struct stack {
  char from[20];
  char to[20];
  int dist;
};

struct stack bt_stack[MAX];  /* pilha de retorno */
struct stack solution[MAX];  /* guarda solu‡oes tempor rias */
void setup(void);
int route(void);
void assert_flight(char *from, char *to, int dist);
void push(char *from, char *to, int dist);
void pop(char *from, char *to, int *dist);
void isflight(char *from, char *to);
void spush(char *from, char *to, int dist);
int find(char *from, char *anywhere);
int match(char *from, char *to);

void main(void)
{
  char from[20], to[20];
  int t, d;

  setup();

  printf("De? ");
  gets(from);
  printf("Para? ");
  gets(to);
  do {
    isflight(from, to);
    d = route();
    tos = 0; /* reinicializa a pilha de retorno */
  } while(d!=0); /* enquanto estiver encontrando solu‡oes */

  t = 0;
  printf("A solu‡ao ¢tima ‚: \n");
  while(t<stos) {
    printf("%s para ", solution[t].from);
    d += solution[t].dist;
    t++;
  }
  printf("%s\n", to);
  printf("A distƒncia ‚ %d\n", d);
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

/* Encontra a menor distƒncia */
route(void)
{
  int dist, t;
  static int old_dist = 32000;

  if(!tos) return 0; /* feito */
  t = 0;
  dist = 0;
  while(t<tos) {
    dist +=bt_stack[t].dist;
    t++;
  }

  /* se menor, entao ache nova solu‡ao */
  if(dist<old_dist && dist) {
    t = 0;
    old_dist = dist;
    stos = 0; /* limpa a rota antiga da pilha de posi‡ao */
    while(t<tos) {
      spush(bt_stack[t].from, bt_stack[t].to, bt_stack[t].dist);
      t++;
    }
  }
  return dist;
}

/* Se h  o v“o entre from e to, entao devolve a distƒncia  do
   v“o; caso contr rio, devolve 0. */
match(char *from, char *to)
{
  register int t;

  for(t=f_pos; t>-1; t--)
    if(!strcmp(flight[t].from, from) &&
       !strcmp(flight[t].to, to)) return flight[t].distance;

  return 0;
}

/* Dado from, encontra anywhere. */
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

/* Determina se h  uma rota entre from e to */
void isflight(char *from, char *to)
{
  int d, dist;
  char anywhere[20];

  /* vˆ no destino */
  if(d=match(from, to)) {
    push(from, to, d);
    return;
  }

  /* tenta outra conexao */
  if(dist=find(from, anywhere)) {
    push(from, to, dist);
    isflight(anywhere, to);
  }
  else if(tos>0) {
    /* retorna */
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

/* pilha de solu‡ao */
void spush(char *from, char *to, int dist)
{
  if(stos<MAX) {
    strcpy(solution[stos].from, from);
    strcpy(solution[stos].to, to);
    solution[stos].dist = dist;
    stos++;
  }
  else printf("Pilha de menor distƒncia cheia.\n");
}
