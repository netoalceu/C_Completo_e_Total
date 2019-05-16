#include <graph.h>
#include <conio.h>

void main(void)
{
  _setvideomode(_VRES16COLOR);

  _arc(100, 100, 200, 200, 100, 100, 200, 200);
  getche();

  _setvideomode(_DEFAULTMODE);
}
