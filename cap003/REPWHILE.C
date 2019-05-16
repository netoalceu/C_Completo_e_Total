#include <stdio.h>
#include <string.h>

void pad(char *s, int length);

void main(void)
{
  char str[80];

  strcpy(str, "Isto ‚ um teste");
  pad(str, 40);
  printf("%d", strlen(str));
}

/* acrescenta espa‡os ao final da string */
void pad(char *s, int length)
{
  int l;

  l = strlen(s);  /* encontra o comprimento */

  while(l<length) {
    s[l] = ' ';  /* insere um espa‡o */
    l++;
  }
  s[l] = '\0';  /* strings precisam terminar com um nulo */
}
