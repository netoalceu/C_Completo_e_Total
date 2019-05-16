#include <graph.h>
#include <conio.h>

void main(void)
{
  short oldstyle;

  _setvideomode(_VRES16COLOR);
  oldstyle = _getlinestyle();
  _moveto(0, 0);

  /* estilo de linha default */
  _lineto(100, 100);

  /* novo estilo de linha */
  _setlinestyle(12345);
  _rectangle(_GBORDER, 100, 100, 200, 200);

  /* estilo anterior restaurado */
  _setlinestyle(oldstyle);
  _rectangle(_GBORDER, 200, 200, 300, 300);
  getche();

  _setvideomode(_DEFAULTMODE);
}
