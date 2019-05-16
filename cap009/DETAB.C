/* O programa substitui espa‡os por tabula‡oes em um arquivo
   texto e fornece verifica‡ao de erros.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 8
#define IN 0
#define OUT 1

void err(int e);

void main(int argc, char *argv[])
{
  FILE *in, *out;
  int tab, i;
  char ch;

  if(argc!=3) {
    printf("uso: detab <entrada> <sa¡da>\n");
    exit(1);
  }

  if((in = fopen(argv[1], "rb"))==NULL) {
    printf("arquivo %s nao pode ser aberto\n", argv[1]);
    exit(1);
  }

  if((out = fopen(argv[2], "wb"))==NULL) {
    printf("arquivo %s nao pode ser aberto\n", argv[2]);
    exit(1);
  }

  tab = 0;
  do {
    ch = getc(in);
    if(ferror(in)) err(IN);
    if(ch=='\t') { /* se encontrou um tab, entao */
      /* envia o n£mero apropriado de espa‡os */
      for(i=tab; i<8; i++) {
        putc(' ', out);
        if(ferror(out)) err(OUT);
      }
      tab = 0;
    }
    else {
      putc(ch, out);
      if(ferror(out)) err(OUT);
      tab++;
      if(tab==TAB_SIZE) tab = 0;
      if(ch=='\n' || ch=='\r') tab = 0;
    }
  } while(!feof(in));
  fclose(in);
  fclose(out);
}

void err(int e)
{
  if(e==IN) printf("erro na entrada\n");
  else printf("erro na sa¡da\n");
  exit(1);
}
