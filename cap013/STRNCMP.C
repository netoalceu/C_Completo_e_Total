#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  if(argc!=3) {
    printf("n£mero incorreto de parametros");
    exit(1);
  }

  if(!strncmp(argv[1], argv[2], 8))
    printf("os nomes de arquivo sao iguais\n");
}
