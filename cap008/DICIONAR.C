/* Um dicion rio simples */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

/* lista de palavras e significados */
char *dic[][40] = {
  "atlas", "um livro de mapas",
  "carro", "um ve¡culo motorizado",
  "telefone", "um dispositivo de comunica‡ao",
  "avi„o", "uma m quina voadora",
  "","" /* nulo termina a lista */
};

void main(void)
{
  char word[80], ch;
  char **p;

  do {
    puts("\nEntre a palavra: ");
    gets(word);

    p = (char **)dic;

    /* encontra a palavra e imprime seu significado */
    do {
      if(!strcmp(*p, word)) {
        puts("significado:");
        puts(*(p+1));
        break;
      }
      if(!strcmp(*p, word)) break;
      p = p + 2;  /* avan‡a na lista */
    } while(*p);
    if(!*p) puts("a palavra nao est  no dicion rio");
    printf("outra? (s/n): ");
    ch = getche();
  } while(toupper(ch) != 'N');
}
