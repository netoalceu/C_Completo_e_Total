#include <stdio.h>
#include <graph.h>
#include <conio.h>
#include <stdlib.h>

void main(void)
{
  long size;
  char far *buf;

  _setvideomode(_VRES16COLOR);

  size = _imagesize(100, 100, 300, 200);
  buf = malloc((size_t) size);
  if(!buf) {
    printf("erro de aloca‡ao\n");
    exit(1);
  }

  _ellipse(_GBORDER, 100, 100, 300, 200);
  _getimage(100, 100, 300, 200, buf);
  _putimage(0, 0, buf, _GPSET);
  getche();

  _setvideomode(_DEFAULTMODE);
}
