#include <stdlib.h>
#include <stdio.h>

void main(void)
{
  for(;;)
    if(getchar()=='A') abort();
}
