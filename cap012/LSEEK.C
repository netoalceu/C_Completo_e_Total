#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 128

void main(int argc, char *argv[])
{
  char buf[BUF_SIZE+1], s[10];
  int fd, sector;

  buf[BUF_SIZE+1] = '\0'; /* termina o buffer com nulo
                             para printf */

  if((fd=open(argv[1], O_RDONLY))==-1) { /*abre para leitura*/
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  do {
    printf("buffer: ");
    gets(s);

    sector = atoi(s); /* obt‚m o setor a ler */

    if(lseek(fd, (long)sector*BUF_SIZE, SEEK_SET)==-1L)
      printf("erro na busca\n");

    if(read(fd, buf, BUF_SIZE)==0) {
      printf("setor fora da faixa\n");
    }
    else
      printf("%s\n", buf);
  } while(sector>0);
  close(fd);
}
