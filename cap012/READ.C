#include <fcntl.h>
#include <io.h>
#include <stdlib.h>
#include <stdio.h>

void main(void)
{
  int fd;
  char buffer[100];

  if((fd=open("test", O_RDONLY))==-1) {
    printf("arquivo nao pode ser aberto");
    exit(1);
  }

  if(read(fd, buffer, 100)!=100) printf("erro de leitura");
}
