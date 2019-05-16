#include <graph.h>
#include <conio.h>

void main(void)
{
   short color;

  _setvideomode(_VRES16COLOR);
  color = _getcolor();
  _ellipse(_GBORDER, 100, 100, 300, 200);
  _setcolor(2);
  _floodfill(150, 150, color);
  getche();

  _setvideomode(_DEFAULTMODE);
}
