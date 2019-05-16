#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void main(void)
{
  int fd;
  char buffer[100];

  if((fd=open("test", O_WRONLY))==-1) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  gets(buffer);

  if(write(fd, buffer, 100)!=100) printf("erro de grava‡„o");
  close(fd);
}
