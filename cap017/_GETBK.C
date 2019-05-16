#include <graph.h>
#include <conio.h>
#include <stdio.h>

void main(void)
{
  _setvideomode(_VRES16COLOR);

  printf("cor de fundo ‚ %ld", _getbkcolor());
  getche();

  _setvideomode(_DEFAULTMODE);
}
