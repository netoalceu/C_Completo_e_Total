/* Demonstra lseek(). */
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUF_SIZE 128

void main(int argc, char *argv[])
{
  char buf[BUF_SIZE+1], s[10];
  int fd, sector;

  if(argc!=2) {
    printf("uso: dump <setor>\n");
    exit(1);
  }

  buf[BUF_SIZE+1] = '\0'; /* o buffer termina com um nulo */

  if((fd=open(argv[1], O_RDONLY))==-1) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  do {
    printf("\n buffer: ");
    gets(s);

    sector = atoi(s); /* obt‚m o setor a ler */

    if(lseek(fd, (long)sector*BUF_SIZE, 0)==-1L)
      printf("erro na busca\n");

    if(read(fd, buf, BUF_SIZE)==0) {
      printf("setor fora da faixa\n");
    }
    else
      printf(buf);
  } while(sector>=0);
  close(fd);
}
