/* KTOD: Do teclado para o disco */
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

  if((fp=fopen(argv[1], "w"))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  do {
    ch = getchar();
    putc(ch, fp);
  } while(ch!='$');

  fclose(fp);
}
