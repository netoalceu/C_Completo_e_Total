#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  int outcome, len, l1,  l2;

  if(argc!=3) {
    printf("n£mero incorreto de parametros");
    exit(1);
  }

  /* encontra o comprimento do menor */
  l1 = strlen(argv[1]);
  l2 = strlen(argv[2]);
  len = l1 < l2 ? l1 : l2;

  outcome = memcmp(argv[1], argv[2], len);
  if(!outcome) printf ("iguais");
  else if(outcome<0) printf("primeiro menor que segundo");
  else printf("primeiro maior que segundo");
}
