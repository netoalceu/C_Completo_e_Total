#include <graph.h>
#include <conio.h>

void main(void)
{
  _setvideomode(_VRES16COLOR);

  _moveto(0, 0);
  _setcolor(3);
  _lineto(600,400);
  getche();

  _setvideomode(_DEFAULTMODE);
}
