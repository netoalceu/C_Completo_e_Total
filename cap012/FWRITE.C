#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  FILE *fp;
  float f=12.23;

  if((fp=fopen("test", "wb"))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  fwrite(&f, sizeof(float), 1, fp);

  fclose(fp);
}
