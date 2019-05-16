#include <stdio.h>

int sqrnum(int num);
int readnum(void);
int prompt(void);

main()
{
  int t;

  for(prompt(); t=readnum(); prompt())
    sqrnum(t);
}

prompt(void)
{
  printf("Entre um n£mero: ");
  return 0;
}

readnum(void)
{
  int t;

  scanf("%d", &t);
  return t;
}

sqrnum(int num)
{
  printf("%d\n", num*num);
  return num*num;
}
