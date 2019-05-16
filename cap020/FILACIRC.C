/* Um exemplo de fila circular usando um buffer para teclado */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 80

char buf[MAX+1];
int spos=0;
int rpos=0;

void qstore(char q);
char qretrieve(void);

void main(void)
{
  register char ch;
  int t;

  buf[80] = NULL;

  /* insere caracteres at‚ que um CR seja digitado */
  for(ch=' ', t=0; t<32000 && ch!='\r'; ++t) {
    if(kbhit()) {
      ch = getch();
      qstore(ch);
    }
    printf("%d ", t);
    if(ch=='\r') {
      /* mostra e esvazia o buffer de teclas */
      printf("\n");
      while((ch=qretrieve())!=NULL) printf("%c", ch);
      printf("\n");
    }
  }
}

/* Armazena caracteres na fila */
void qstore(char q)
{
  if(spos+1==rpos || (spos+1==MAX && !rpos)) {
    printf("lista cheia\n");
    return;
  }
  buf[spos] = q;
  spos++;
  if(spos==MAX) spos = 0; /* reinicia */
}

/* Recupera um caractere */
char qretrieve(void)
{
  if(rpos==MAX) rpos = 0;  /* reinicia */
  if(rpos==spos) return NULL;

  rpos++;
  return buf[rpos-1];
}
