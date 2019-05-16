#include <stdio.h>

void main(int argc, char *argv[])
{
  if(unlink(argv[1])) printf ("erro de remo‡„o\n");
}
