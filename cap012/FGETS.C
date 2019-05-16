#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  FILE *fp;
  char str[128];

  if((fp=fopen(argv[1], "r"))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  while(!feof(fp)) {
    if(fgets(str, 128, fp)) printf("%s", str);
  }

  fclose(fp);
}
