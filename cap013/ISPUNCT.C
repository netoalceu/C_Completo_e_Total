#include <ctype.h>
#include <stdio.h>

void main(void)
{
  char ch;

  for(;;) {
    ch = getchar();
    if(ch==' ') break;
    if(ispunct(ch)) printf("%c ‚ sinal de pontua‡ao\n", ch);
  }
}

