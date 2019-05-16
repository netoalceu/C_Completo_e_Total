#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void quick(char *item, int count);
void qs(char *item, int left, int right);

void main(void)
{
  char s[80];

  printf("Digite uma string: ");
  gets(s);
  quick(s, strlen(s));
  printf("A string ordenada: %s\n", s);
}

void quick(char *item, int count)
{
  qs(item, 0, count-1);
}

void qs(char *item, int left, int right)
{
  register int i, j;
  char x, y;

  i = left; j = right;
  x = item[(left+right)/2];

  do {
    while(item[i]<x && i<right) i++;
    while(x<item[j] && j>left) j--;

    if(i<=j) {
      y = item[i];
      item[i] = item[j];
      item[j] = y;
      i++; j--;
    }
  } while(i<=j);

  if(left<j) qs(item, left, j);
  if(i<right) qs(item, i, right);
}

