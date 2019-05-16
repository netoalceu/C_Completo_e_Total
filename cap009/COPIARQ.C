/* Copia um arquivo */
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  FILE *in, *out;
  char ch;

  if(argc!=3) {
    printf("Vocˆ esqueceu de informar o nome do arquivo\n");
    exit(1);
  }

  if((in=fopen(argv[1], "rb"))==NULL) {
    printf("arquivo fonte nao pode ser aberto\n");
    exit(1);
  }

  if((out=fopen(argv[2], "wb"))==NULL) {
    printf("arquivo destino nao pode ser aberto\n");
    exit(1);
  }

  /* Este c¢digo copia de fato o arquivo */
  while(!feof(in)) {
    ch = getc(in);
    if(!feof(in)) putc(ch, out);
  }

  fclose(in);
  fclose(out);
}
