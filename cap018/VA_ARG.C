#include <stdio.h>
#include <stdarg.h>

double sum_series(int num, ...);

/* exemplo de argumentos de comprimento vari vel
   - soma de uma s‚rie
*/

void main(void)
{
  double d;

  d = sum_series(5, 0.5, 0.25, 0.125, 0.0625, 0.03125);

  printf("soma da s‚rie: %f\n", d);
}

double sum_series(int num, ...)
{
  double sum=0.0, t;
  va_list argptr;

  /* inicializa argptr */
  va_start(argptr, num);

  /* soma a s‚rie */
  for( ; num; num--) {
    t = va_arg(argptr, double); /* obt‚m pr¢ximo argumento */
    sum += t;
  }

  /* finaliza a lista de argumentos */
  va_end(argptr);
  return sum;
}
