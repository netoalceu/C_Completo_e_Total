/* Exemplo de fscanf() - fprintf() */
#include <stdio.h>
#include <io.h>
#include <stdlib.h>

void main(void)
{
  FILE *fp;
  char s[80];
  int t;

  if((fp=fopen("test", "w")) == NULL) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  printf("entre com uma string e um n£mero: ");
  fscanf(stdin, "%s%d", s, &t); /* lˆ do teclado    */

  fprintf(fp, "%s %d", s, t);   /* grava no arquivo */
  fclose(fp);

  if((fp=fopen("test", "r")) == NULL) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  fscanf(fp, "%s%d", s, &t);      /* lˆ do arquivo   */
  fprintf(stdout, "%s %d", s, t); /* imprime na tela */
}
