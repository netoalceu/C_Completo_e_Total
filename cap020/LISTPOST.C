/* Um programa simples de lista postal que ilustra o
   uso e a manuten‡ao de listas duplamente encadeadas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct address {
  char name[30];
  char street[40];
  char city[20];
  char state[3];
  char zip[10]; /* guarda ceps dos EUA e Canad  */
  struct address *next; /* ponteiro para a pr¢xima entrada */
  struct address *prior; /* ponteiro para o registro anterior */
} list_entry;

struct address *start;  /* ponteiro para a primeira entrada
                           da lista */
struct address *last;  /* ponteiro para a £ltima entrada */
struct address *find(char *);

void enter(void), search(void), save(void);
void load(void), list(void);
void delete(struct address **, struct address **);
void dls_store(struct address *i, struct address **start,
               struct address **last);
void inputs(char *, char *, int), display(struct address *);

int menu_select(void);

void main(void)
{
  start = last = NULL;  /* inicializa os ponteiros de topo
                           e fundo */

  for(;;) {
    switch(menu_select()) {
      case 1: enter();
        break;
      case 2: delete(&start, &last);
        break;
      case 3: list();
        break;
      case 4: search(); /* encontra uma rua */
        break;
      case 5: save(); /* grava a lista no disco */
        break;
      case 6: load(); /* lˆ do disco */
        break;
      case 7: exit(0);
    }
  }
}

/* Seleciona uma opera‡ao. */
menu_select(void)
{
  char s[80];
  int c;

  printf("1. Inserir um nome\n");
  printf("2. Deletar um nome\n");
  printf("3. Listar o arquivo\n");
  printf("4. Pesquisar\n");
  printf("5. Gravar o arquivo\n");
  printf("6. Carregar o arquivo\n");
  printf("7. Sair\n");
  do {
    printf("\nEntre com sua escolha: ");
    gets(s);
    c =atoi(s);
  } while(c<0 || c>7);
  return c;
}

/* Insere nomes e endere‡os */
void enter(void)
{
  struct address *info;

  for(;;) {
    info = (struct address *)malloc(sizeof(list_entry));
    if(!info) {
      printf("\nsem mem¢ria");
      return;
    }
    inputs("Entre o nome: ", info->name, 30);
    if(!info->name[0]) break; /* para a inser‡ao */
    inputs("Entre a rua: ", info->street, 40);
    inputs("Entre a cidade: ", info->city, 20);
    inputs("Entre o estado: ", info->state, 3);
    inputs("Entre o cep: ", info->zip, 10);

    dls_store(info, &start, &last);
  } /* la‡o de entrada */
}

/* Esta fun‡ao lˆ uma string de comprimento m ximo count e evita que
a string seja ultrapassada. Ela tamb‚m apresenta uma mensagem de prompt. */
void inputs(char *prompt, char *s, int count)
{
  char p[255];

  do {
    printf(prompt);
    gets(p);
    if(strlen(p)>count) printf("\nMuito comprido\n");
  } while(strlen(p)>count);
  strcpy(s, p);
}

/* Cria uma lista duplamente encadeada ordenada */
void dls_store(
  struct address *i,    /* novo elemento */
  struct address **start, /* primeiro elemento da lista */
  struct address **last  /* £ltimo elemento da lista */
)
{
  struct address *old, *p;

  if(*last==NULL) {  /* primeiro elemento da lista */
    i->next = NULL;
    i->prior = NULL;
    *last = i;
    *start = i;
    return;
  }

  p = *start; /* come‡a no topo da lista */

  old = NULL;
  while(p) {
    if(strcmp(p->name, i->name)<0) {
      old = p;
      p = p->next;
    }
    else {
      if(p->prior) {
        p->prior->next = i;
        i->next = p;
        i->prior = p->prior;
        p->prior = i;
        return;
      }
      i->next = p; /* novo primeiro elemento */
      i->prior = NULL;
      p->prior = i;
      *start = i;
      return;
    }
  }
  old->next = i; /* coloca no final */
  i->next = NULL;
  i->prior = old;
  *last = i;
}

/* Remove um elemento da lista */
void delete(struct address **start, struct address **last)
{
  struct address *info, *find();
  char s[80];

  inputs("Entre o nome: ", s, 30);
  info = find(s);
  if(info) {
    if(*start==info) {
      *start=info->next;
      if(*start) (*start)->prior = NULL;
      else *last = NULL;
    }
    else {
      info->prior->next = info->next;
      if(info!=*last)
          info->next->prior = info->prior;
      else
        *last = info->prior;
    }
    free(info); /* devolve mem¢ria para o sistema */
  }
}

/* Encontra um endere‡o */
struct address *find(char *name)
{
  struct address *info;

  info = start;
  while(info) {
    if(!strcmp(name, info->name)) return info;
    info = info->next;  /* obt‚m novo endere‡o */
  }
  printf("Nome nao encontrado.\n");
  return NULL; /* nao encontrou */
}

/* Mostra a lista completa */
void list(void)
{
  struct address *info;
  info = start;
  while(info) {
    display(info);
    info = info->next;   /* obt‚m pr¢ximo endere‡o */
  }
  printf("\n\n");
}

/* Esta fun‡ao imprime os campos de cada endere‡o. */
void display(struct address *info)
{
  printf("%s\n", info->name);
  printf("%s\n", info->street);
  printf("%s\n", info->city);
  printf("%s\n", info->state);
  printf("%s\n", info->zip);
  printf("\n\n");
}

/* Procura por um nome na lista. */
void search(void)
{
  char name[40];
  struct address *info, *find();

  printf("Entre com o nome a procurar: ");
  gets(name);
  info = find(name);
  if(!info) printf("nao encontrou\n");
  else display(info);
}

/* Salva o arquivo em disco. */
void save(void)
{
  struct address *info;
  FILE *fp;
  fp = fopen("mlist", "wb");

  if(!fp) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }
  printf("\nsalvando arquivo\n");

  info = start;
  while(info) {
    fwrite(info, sizeof(struct address), 1, fp);
    info = info->next; /* obt‚m pr¢ximo endere‡o */
  }
  fclose(fp);
}

/* Carrega o arquivo de endere‡o. */
void load()
{
  struct address *info;
  FILE *fp;
  fp = fopen("mlist", "rb");
  if(!fp) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }
  /* libera qualquer mem¢ria previamente alocada */
  while(start) {
    info = start->next;
    free(info);
    start = info;
  }

  /* reinicializa os ponteiros de in¡cio e fim */
  start = last = NULL;

  printf("\nCarregando arquivo\n");
  while(!eof(fp)) {
    info = (struct address *) malloc(sizeof(struct address));
    if(!info) {
      printf("sem mem¢ria");
      return;
    }
    if(1!=fread(info, sizeof(struct address), 1, fp)) break;
    dls_store(info, &start, &last);
  }
  fclose(fp);
}
