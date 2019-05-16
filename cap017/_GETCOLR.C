#include <graph.h>
#include <conio.h>
#include <stdio.h>

void main(void)
{
  short color;

  _setvideomode(_VRES16COLOR);

  color = _getcolor();
  printf("cor ‚ %hd", color);
  getche();

  _setvideomode(_DEFAULTMODE);
}
