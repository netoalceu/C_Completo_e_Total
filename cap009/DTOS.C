/* DTOS: Um programa que lˆ arquivos e mostra-os na tela */
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  FILE *fp;
  char ch;

  if(argc!=2) {
    printf("vocˆ esqueceu de entrar o nome do arquivo\n");
    exit(1);
  }

  if((fp=fopen(argv[1], "r"))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  ch = getc(fp);  /* lˆ um caractere */

  while (ch!=EOF) {
    putchar(ch);  /* imprime na tela */
    ch = getc(fp);
  }

  fclose(fp);
}
