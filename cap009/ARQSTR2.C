#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
  char str[80];
  FILE *fp;

  if((fp = fopen("TEST", "w+"))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  do {
    printf("entre uma string (CR para sair):\n");
    gets(str);
    strcat(str, "\n");  /* acrescenta uma nova linha */
    fputs(str, fp);
  } while(*str!='\n');

  /* agora, lˆ e mostra o arquivo */
  rewind(fp); /* reinicializa o indicador de posi‡ao de arquivo
                 para o come‡o do arquivo. */
  while(!feof(fp)) {
    fgets(str, 79, fp);
    printf(str);
  }
}
