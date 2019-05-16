#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  FILE *fp;

  printf("Isso ser  mostrado na tela\n");

  if((fp=freopen("OUT", "w" , stdout))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  printf("isso ser  escrito no arquivo OUT");

  fclose(fp);
}
