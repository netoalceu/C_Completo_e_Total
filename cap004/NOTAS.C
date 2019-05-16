#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/* Um banco de dados simples para notas de alunos */
#define CLASSES  3
#define GRADES  30

int grade [CLASSES][GRADES];

void enter_grades(void);
int get_grade(int num);
void disp_grades(int g[][GRADES]);

void main(void)
{
  char ch, str[80];

  for(;;) {
    do {
      printf("(E)ntrar notas\n");
      printf("(M)ostrar notas\n");
      printf("(S)air\n");
      gets(str);
      ch = toupper(*str);
    } while(ch!='E' && ch!='M' && ch!='S');

    switch(ch) {
      case 'E':
        enter_grades();
        break;
      case 'M':
        disp_grades(grade);
        break;
      case 'S':
        exit(0);
    }
  }
}

/* Entra com a nota dos alunos. */
void enter_grades(void)
{
  int t, i;

  for(t=0; t<CLASSES; t++) {
    printf("Turma # %d:\n", t+1);
    for(i=0; i<GRADES; ++i)
      grade[t][i]= get_grade(i);
  }
}

/* Lˆ uma nota. */
int get_grade(int num)
{
  char s[80];

  printf("entre a nota do aluno # %d:\n",num+1);
  gets(s);
  return(atoi(s));
}

/* Mostra as notas. */
void disp_grades(int g[][GRADES])
{
  int t, i;

  for(t=0; t<CLASSES; ++t) {
    printf("Turma # %d:\n", t+1);
    for(i=0; i<GRADES; ++i)
      printf("aluno #%d e %d\n", i+1, g[t][i]);
  }
}
