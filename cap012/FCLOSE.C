#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  FILE *fp;

  if((fp=fopen("test", "rb"))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }
  if(fclose(fp)) printf("erro no fechamento do arquivo\n");
}
