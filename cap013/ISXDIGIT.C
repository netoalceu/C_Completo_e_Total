#include <ctype.h>
#include <stdio.h>

void main(void)
{
  char ch;

  for(;;) {
    ch = getchar();
    if(ch==' ') break;
    if(isxdigit(ch)) printf("%c ‚ d¡gito hexadecimal\n", ch);
  }
}
