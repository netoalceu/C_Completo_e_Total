/* Lˆ e escreve usando E/S sem buffer */
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define BUF_SIZE 128

void input(char *buf, int fd1);
void display(char *buf, int fd2);

void main(void)
{
  char buf[BUF_SIZE];
  int fd1, fd2;

  if((fd1=open("test", O_WRONLY))==-1) { /* abre para grava‡„o */
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  input(buf, fd1);

  /* agora fecha o arquivo e lˆ de volta */
  close(fd1);

  if((fd2=open("test", O_RDONLY))==-1) { /* abre para leitura */
    printf("arquivo nao pode ser aberto\n");
    exit(1);
  }

  display(buf, fd2);
  close(fd2);
}

/* Insere texto */
void input(char *buf, int fd1)
{
  register int t;

  do {
    for(t=0; t<BUF_SIZE; t++) buf[t] = '\0';
    gets(buf); /* lˆ caracteres do teclado */
    if(write(fd1, buf, BUF_SIZE) != BUF_SIZE) {
      printf("erro de grava‡„o\n");
      exit(1);
    }
  } while(strcmp(buf, "quit"));
}

/* Mostra o arquivo */
void display(char *buf, int fd2)
{
  for(;;) {
    if(read(fd2, buf, BUF_SIZE)==0) return;
    printf("%s\n", buf);
  }
}
