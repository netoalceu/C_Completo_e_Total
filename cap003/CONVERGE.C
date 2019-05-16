/* Versao para Microsoft */
#include <stdio.h>
#include <graph.h>
#include <string.h>

void converge(int line, char *message);

void main(void)
{
  converge(10, "Isto ‚ um teste de converge().");
}

/* Esta fun‡ao mostra uma string iniciando do lado esquerdo da
linha especificada. Ela escreve caracteres de ambas as
extremidades, convergindo para o centro. */
void converge(int line, char *message)
{
  int i, j;

  for(i=1, j=strlen(message); i<j; i++, j--) {
    _settextposition(line, i);
    printf("%c", message[i-1]);
    _settextposition(line, j);
    printf("%c", message[j-1]);
  }
}
