#include <io.h>
#include <sys\stat.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  int fd;

  if((fd=creat("test", S_IWRITE))==-1) {
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }
}
