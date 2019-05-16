#include <graph.h>
#include <conio.h>

void main(void)
{
  int i;

  _setvideomode(_VRES16COLOR);

  i = _getcolor();
  for( ; i; i--) {
    _setcolor(i);
    _moveto(i*10, 0);
    _lineto(i*10, 100);
  }
  getche();

  _setvideomode(_DEFAULTMODE);
}
