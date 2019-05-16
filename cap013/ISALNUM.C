#include <ctype.h>
#include <stdio.h>

void main(void)
{
  char ch;

  for(;;) {
    ch = getc(stdin);
    if(ch==' ') break;
    if(isalnum(ch)) printf("%c ‚ alfanum‚rico\n", ch);
  }
}
