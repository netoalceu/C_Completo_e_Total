/* DTOS: Um programa que l� arquivos e mostra-os na tela */
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  FILE *fp;
  char ch;

  if(argc!=2) {
    printf("voc� esqueceu de entrar o nome do arquivo\n");
    exit(1);
  }

  if((fp=fopen(argv[1], "r"))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  ch = getc(fp);  /* l� um caractere */

  while (ch!=EOF) {
    putchar(ch);  /* imprime na tela */
    ch = getc(fp);
  }

  fclose(fp);
}
