#include <conio.h>

void main(void)
{
  char s[23];

  s[0] = 20;
  cputs("digite uma string: ");
  cgets(s);
  cputs(&s[2]);
}
