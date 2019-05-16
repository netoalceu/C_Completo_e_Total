#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  FILE *fp;
  int sum=0;

  if((fp=fopen("intteste", "rb"))==NULL) {
    printf("arquivo nao pode ser aberto");
    exit(1);
  }

  while(!feof(fp))
    sum = getw(fp)+sum;

  printf("a soma ‚ %d", sum);

  fclose(fp);
}
