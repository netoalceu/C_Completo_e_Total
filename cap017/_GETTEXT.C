#include <graph.h>
#include <conio.h>
#include <stdio.h>

void main(void)
{
  int color;

  _setvideomode(_VRES16COLOR);

  color = _gettextcolor();
  printf("a cor de texto default ‚ %d", color);
  _settextcolor(3);
  _settextposition(10, 1);
  _outtext("isto est  em uma cor diferente\n");
  getche();

  _setvideomode(_DEFAULTMODE);
}
