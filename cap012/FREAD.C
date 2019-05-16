#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  FILE *fp;
  float bal[10];

  if((fp=fopen("test", "rb"))==NULL) {
    printf("Arquivo nao pode ser aberto\n");
    exit(1);
  }

  if(fread(bal, sizeof(float), 10, fp)!=10) {
    if(feof(fp)) printf("fim de arquivo prematuro");
    else printf("erro na leitura do arquivo");
  }

  fclose(fp);
}
