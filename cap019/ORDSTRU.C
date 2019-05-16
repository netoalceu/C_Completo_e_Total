/* Ordena‡ao em disco para estruturas do tipo address */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 4 /* Este ‚ um n£mero arbitr rio
                          que deve ser determinado
                          dinamicamente para cada lista. */

struct address {
  char name[30];
  char street[40];
  char city[20];
  char state[3];
  char zip[10];
}ainfo;

struct address addrs[NUM_ELEMENTS] = {
  "A. Alexander", "101 1st St", "Olney", "Ga", "55555",
  "B. Bertrand", "22 2nd Ave", "Oakland", "Pa", "34232",
  "C. Carlisle", "33 3rd Blvd", "Ava", "Or", "92000",
  "D. Dodger", "4 Fourth Dr", "Fresno", "Mi", "45678",
};

void quick_disk(FILE *fp, int count);
void qs_disk(FILE *fp, int left, int right);
void swap_all_fields(FILE *fp, long i, long j);
char *get_zip(FILE *fp, long rec);

void main(void)
{
  FILE *fp;

  /* primeiro cria um arquivo a ser ordenado */
  if((fp=fopen("mlist", "wb"))==NULL) {
    printf("arquivo n„o pode ser aberto para grava‡„o\n");
    exit(1);
  }
  printf("Gravando dados desordenados no arquivo.\n");
  fwrite(addrs, sizeof(addrs), 1, fp);
  fclose(fp);

  /* agora ordena o arquivo */
  if((fp=fopen("mlist", "rb+"))==NULL) {
    printf("arquivo nao pode ser aberto para leitura/altera‡„o\n");
    exit(1);
  }

  printf("Ordenando arquivo em disco.\n");
  quick_disk(fp, NUM_ELEMENTS);
  fclose(fp);
  printf("Lista ordenada.\n");
}

/* Um quicksort para arquivos */
void quick_disk(FILE *fp, int count)
{
  qs_disk(fp, 0, count-1);
}

void qs_disk(FILE *fp, int left, int right)
{
  long int i, j;
  char x[100];
  i = left; j = right;

  strcpy(x, get_zip(fp,(long)(i+j)/2)); /* obt‚m o CEP do meio */

  do {
    while(strcmp(get_zip(fp,i),x)<0 && i<right) i++;
    while(strcmp(get_zip(fp,j),x)>0 && j>left) j--;

    if(i<=j) {
      swap_all_fields(fp, i, j);
      i++; j--;
    }
  } while(i<=j);

  if(left<j)  qs_disk(fp, left, (int) j);
  if(i<right) qs_disk(fp, (int) i, right);
}

void swap_all_fields(FILE *fp, long i, long j)
{
  char a[sizeof(ainfo)], b[sizeof(ainfo)];

  /* primeiro lˆ os registros i e j */
  fseek(fp, sizeof(ainfo)*i, SEEK_SET);
  fread(a, sizeof(ainfo), 1, fp);
  fseek(fp, sizeof(ainfo)*j, SEEK_SET);
  fread(b, sizeof(ainfo), 1, fp);

  /* em seguida escreve-os de volta em posi‡oes diferentes */
  fseek(fp, sizeof(ainfo)*j, SEEK_SET);
  fwrite(a, sizeof(ainfo), 1, fp);
  fseek(fp, sizeof(ainfo)*i, SEEK_SET);
  fwrite(b, sizeof(ainfo), 1, fp);
}

/* Devolve um ponteiro para o CEP */
char *get_zip(FILE *fp, long rec)
{
  struct address *p;

  p = &ainfo;

  fseek(fp, rec*sizeof(ainfo), SEEK_SET);
  fread(p, sizeof(ainfo), 1, fp);

  return ainfo.zip;
}
