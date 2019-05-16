#include <ctype.h>
#include <stdio.h>

void main(void)
{
  char ch;

  for(;;) {
    ch = getchar();
    if(isspace(ch)) printf("%c ‚ espa‡o vazio\n", ch);
    if(ch==' ') break;
  }
}
