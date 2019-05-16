#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* obt‚m a semente para rand da hora do sistema
   e mostra os primeiros 10 n£meros
*/

void main(void)
{
  int i, stime;
  long ltime;

  /* obt‚m a hora de calend rio atual */
  ltime =time(NULL);
  stime = (unsigned) ltime/2;
  srand(stime);

  for(i=0; i<10;i++) printf("%d ", rand());
}

