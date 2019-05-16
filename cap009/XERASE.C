/* Verifica‡ao dupla antes de apagar */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main(int argc, char *argv[])
{
  char str[80];

  if(argc!=2) {
    printf("uso: xerase <nomearq>\n");
    exit(1);
  }

  printf("apaga %s? (S/N): ", argv[1]);
  gets(str);

  if(toupper(*str)=='S')
    if(remove(argv[1])) {
      printf("arquivo nao pode ser apagado\n");
      exit(1);
    }
  return 0; /* retorna sucesso ao SO */
}
