#include <graph.h>
#include <conio.h>
#include <stdlib.h>

void main(void)
{
  short color, i;
  unsigned char oldmask[8];
  unsigned char newmask[8];

  /* obt‚m alguns valores rand“micos para newmask */
  for(i=0; i<8; i++) newmask[i] = rand()%255;

  _setvideomode(_VRES16COLOR);

  color = _getcolor();
  _ellipse(_GBORDER, 100, 100, 300, 200);
  _setcolor(2);
  _getfillmask(oldmask);
  _setfillmask(newmask);
  _floodfill(150, 150, color);
  _setfillmask(oldmask);
  getche();

  _setvideomode(_DEFAULTMODE);
}
