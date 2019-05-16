#include <graph.h>
#include <conio.h>
#include <stdio.h>

void main(void)
{
  _setvideomode(_VRES16COLOR);

  _settextcolor(4);
  _outtext("isto est  em vermelho\n");
  _getche();

  _setvideomode(_DEFAULTMODE);
}
