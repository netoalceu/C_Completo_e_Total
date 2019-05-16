#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  FILE *fp;

  if((fp = fopen("test", "wb"))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  fprintf(fp, "isto e um teste. %d %f", 10, 20.01);
  fclose(fp);
}
