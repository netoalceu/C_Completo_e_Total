#include <graph.h>
#include <conio.h>

void main(void)
{
  _setvideomode(_VRES16COLOR);

  _pie(_GBORDER, 100, 100, 300, 300, 300, 10, 100, 300);
  getche();

  _setvideomode(_DEFAULTMODE);
}
