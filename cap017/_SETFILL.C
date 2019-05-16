#include <graph.h>
#include <conio.h>
#include <stdlib.h>

void main(void)
{
  short i;
  unsigned char newmask[8];

  /* obt‚m alguns valores rand“micos para newmask */
  for(i=0; i<8; i++) newmask[i] = rand()%255;

  _setvideomode(_VRES16COLOR);

  _setfillmask(newmask);
  _ellipse(_GFILLINTERIOR, 100, 100, 300, 200);
  getche();

  _setvideomode(_DEFAULTMODE);
}
