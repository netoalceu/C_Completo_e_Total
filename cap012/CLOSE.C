#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  int fd;

  if((fd=open(argv[1], O_RDONLY))==-1) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  printf("arquivo j  existe\n");
  if(close(fd)) printf("erro no fechamento do arquivo\n");
}
