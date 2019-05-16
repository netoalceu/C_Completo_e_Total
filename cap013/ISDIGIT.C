#include <ctype.h>
#include <stdio.h>

void main(void)
{
  char ch;

  for(;;) {
    ch = getchar();
    if(ch==' ') break;
    if(isdigit(ch)) printf("%c ‚ um d¡gito\n", ch);
  }
}
