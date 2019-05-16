#include <ctype.h>
#include <stdio.h>

void main(void)
{
  char ch;

  for(;;) {
    ch = getchar();
    if(ch==' ') break;
    if(isupper(ch)) printf("%c e mai£sculo\n", ch);
  }
}
