#include <graph.h>
#include <conio.h>

void main(void)
{
  _setvideomode(_VRES16COLOR);
  _setcolor(3);
  _ellipse(_GBORDER, 100, 100, 300, 200);
  getche();

  _setvideomode(_DEFAULTMODE);
}
