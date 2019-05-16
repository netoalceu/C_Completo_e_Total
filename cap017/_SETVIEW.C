#include <graph.h>
#include <conio.h>

void main(void)
{
  _setvideomode(_VRES16COLOR);

  _setviewport(200, 200, 300, 300);
  _moveto(0, 0); _setcolor(3);
  _lineto(600, 400); /* esta linha ser  cortada */
  getche();

  _setvideomode(_DEFAULTMODE);
}
