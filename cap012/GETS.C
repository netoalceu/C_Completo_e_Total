#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  FILE *fp;
  char fname[128];

  printf("Digite o nome do arquivo: ");
  gets(fname);

  if((fp=fopen(fname, "r"))==NULL) {
    printf("arquivo nao pode ser aberto");
    exit(1);
  }

  fclose(fp);
}
