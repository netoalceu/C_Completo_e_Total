/* Um exemplo simples de lista postal usando uma
   matriz de estruturas. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct addr {
  char name[30];
  char street[40];
  char city[20];
  char state[3];
  unsigned long int zip;
} addr_info[MAX];

void init_list(void), enter(void);
void delete(void), list(void);
int menu_select(void), find_free(void);

void main(void)
{
  char choice;

  init_list(); /* inicializa a matriz de estruturas */
  for(;;) {
    choice=menu_select();
    switch(choice) {
      case 1: enter();
        break;
      case 2: delete();
        break;
      case 3: list();
        break;
      case 4: exit(0);
    }
  }
}

/* Inicializa a lista. */
void init_list(void)
{
  register int t;
  for(t=0; t<MAX; ++t) addr_info[t].name[0] = '\0';
}

/* Obt‚m a sele‡ao */
menu_select(void)
{
  char s[80];
  int c;

  printf("1. Inserir um nome\n");
  printf("2. Excluir um nome\n");
  printf("3. Listar o arquivo\n");
  printf("4. Sair\n");
  do {
    printf("\nEntre com sua escolha: ");
    gets(s);
    c = atoi(s);
  } while(c<0 || c>4);
  return c;
}

/* Insere os endere‡os na lista */
void enter(void)
{
  int slot;
  char s[80];

  slot = find_free();
  if(slot==-1) {
    printf("\nlista cheia");
    return;
  }

  printf("entre o nome: ");
  gets(addr_info[slot].name);

  printf("entre a rua: ");
  gets(addr_info[slot].street);

  printf("entre a cidade: ");
  gets(addr_info[slot].city);

  printf("entre o estado: ");
  gets(addr_info[slot].state);

  printf("entre o cep: ");
  gets(s);
  addr_info[slot].zip = strtoul(s, '\0', 10);
}

/* Encontra uma estrutura nao usada. */
find_free(void)
{
  register int t;

  for(t=0; addr_info[t].name[0] && t<MAX; ++t);

  if(t==MAX) return -1; /* nenhum elemento livre */
  return t;
}

/* Apaga um endere‡o */
void delete(void)
{
  register int slot;
  char s[80];

  printf("entre o registro #: ");
  gets(s);
  slot = atoi(s);
  if(slot>=0 && slot < MAX)
    addr_info[slot].name[0] = '\0';
}

/* Mostra a lista na tela. */
void list(void)
{
  register int t;

  for(t=0; t<MAX; ++t) {
    if(addr_info[t].name[0]) {
      printf("%s\n", addr_info[t].name);
      printf("%s\n", addr_info[t].street);
      printf("%s\n", addr_info[t].city);
      printf("%s\n", addr_info[t].state);
      printf("%lu\n", addr_info[t].zip);
    }
  }
  printf("\n\n");
}
