#include <ctype.h>
#include <stdio.h>

void main(void)
{
  char ch;

  for(;;) {
    ch = getchar();
    if(ch==' ') break;
    if(islower(ch)) printf("%c ‚ min£sculo\n", ch);
  }
}
