/* Miniagenda */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char *p[MAX], *qretrieve(void);
int spos = 0;
int rpos = 0;
void enter(void), qstore(char *q), review(void), delete(void);

void main(void)
{
  char s[80];
  register int t;

  for(t=0; t<MAX; ++t) p[t] = NULL; /* inicializa matriz com NULL */

  for(;;) {
    printf("Inserir, Listar, Remover, Sair: ");
    gets(s);
    *s = toupper(*s);

    switch(*s) {
      case 'I':
        enter();
        break;
      case 'L':
        review();
        break;
      case 'R':
        delete();
        break;
      case 'S':
        exit(0);
    }
  }
}

/* Insere um evento na fila */
void enter(void)
{
  char s[256], *p;

  do {
    printf("Entre com o evento %d: ", spos+1);
    gets(s);
    if(*s==0) break; /* nenhuma entrada */
    p = malloc(strlen(s) + 1);
    if(!p) {
      printf("Sem mem¢ria.\n");
      return;
    }
    strcpy(p, s);
    if(*s) qstore(p);
  }while(*s);
}

/* vˆ o que h  na fila */
void review(void)
{
  register int t;

  for(t=rpos; t<spos; ++t)
    printf("%d. %s\n", t+1, p[t]);
}

/* apaga um evento da fila */
void delete(void)
{
  char *p;

  if((p=qretrieve())==NULL) return;
  printf("%s\n", p);
}

/* armazena um evento */
void qstore(char *q)
{
  if(spos==MAX) {
    printf("lista cheia\n");
    return;
  }
  p[spos] = q;
  spos++;
}

/* recupera um evento */
char *qretrieve(void)
{
  if(rpos==spos) {
    printf("Sem eventos.\n");
    return NULL;
  }
  rpos++;
  return p[rpos-1];
}
