/* Um programa de lista postal muito simples */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct list_type {
  char name[40];
  char street[40];
  char city[30];
  char state[3];
  char zip[10];
} list[SIZE];

int menu(void);
void init_list(void), enter(void);
void display(void), save(void);
void load(void);

void main(void)
{
  char choice;

  init_list();

  for(;;) {
    choice = menu();
    switch(choice) {
      case 'i': enter();
        break;
      case 'v': display();
        break;
      case 's': save();
        break;
      case 'c': load();
        break;
      case 't': exit(0);
    }
  }
}

/* Inicializa a lista. */
void init_list(void)
{
  register int t;
  for(t=0; t<SIZE; t++) *list[t].name = '\0';
  /* um nome de comprimento zero significa vazio */
}

/* poe os nomes na lista */
void enter(void)
{
  register int i;

  for(i=0; i<SIZE; i++)
    if(!*list[i].name) break;

  if(i==SIZE) {
    printf("lista cheia\n");
    return;
  }

  printf("nome: ");
  gets(list[i].name);

  printf("rua: ");
  gets(list[i].street);

  printf("cidade: ");
  gets(list[i].city);

  printf("estado: ");
  gets(list[i].state);

  printf("CEP: ");
  gets(list[i].zip);
}

/* mostra a lista */
void display(void)
{
  register int t;

  for(t=0; t<SIZE; t++) {
    if(*list[t].name) {
      printf("%s\n", list[t].name);
      printf("%s\n", list[t].street);
      printf("%s\n", list[t].city);
      printf("%s\n", list[t].state);
      printf("%s\n\n", list[t].zip);
    }
  }
}

/* Salva a lista. */
void save(void)
{
  FILE *fp;
  register int i;

  if((fp=fopen("maillist", "wb"))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    return;
  }

  for(i=0; i<SIZE; i++)
    if(*list[i].name)
      if(fwrite(&list[i],
        sizeof(struct list_type), 1, fp)!=1)
          printf("erro de grava‡„o no arquivo\n");
}

/* Carrega o arquivo */
void load(void)
{
  FILE *fp;
  register int i;

  if((fp=fopen("maillist", "rb"))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    return;
  }

  init_list();
  for(i=0; i<SIZE; i++)
    if(fread(&list[i],
      sizeof(struct list_type), 1, fp)!=1) {
        if(feof(fp)) return;
        printf("erro de leitura no arquivo\n");
    }

  fclose(fp);
}

/* obt‚m uma sele‡ao do menu */
menu(void)
{
  char s[80];

  do {
    printf("(I)nserir\n");
    printf("(V)isualizar\n");
    printf("(C)arregar\n");
    printf("(S)alvar\n");
    printf("(T)erminar\n");
    printf("escolha: ");
    gets(s);
  } while(!strchr("ivcst", tolower(*s)));
  return tolower(*s);
}
