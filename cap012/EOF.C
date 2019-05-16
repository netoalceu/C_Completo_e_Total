#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  int fd;
  char ch;

  if((fd=open(argv[1], O_RDONLY))==-1) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  while(!eof(fd)) {
    read(fd, &ch, 1); /* lˆ um caractere por vez */
    printf("%c", ch);
  }
  close(fd);
}
