/* Um exemplo de jogo-da-velha simples */
#include <stdio.h>
#include <stdlib.h>

char matrix[3][3]; /* a matriz do jogo */

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

void main(void)
{
  char done;

  printf("Este ‚ o jogo da velha.\n");
  printf("Vocˆ estar  jogando contra o computador.\n");
  done = ' ';
  init_matrix();
  do {
    disp_matrix();
    get_player_move();
    done = check();  /* verifica se h  vencedor */
    if(done!=' ') break;  /* vencedor! */
    get_computer_move();
    done = check();  /* verifica se h  vencedor */
  } while(done==' ');
  if(done=='X') printf("Vocˆ ganhou!\n");
  else printf("Eu ganhei!!!\n");
  disp_matrix();  /* mostra as posi‡oes finais */
}

/* Inicializa a matriz */
void init_matrix(void)
{
  int i, j;

  for(i=0; i<3; i++)
     for(j=0; j<3; j++) matrix[i][j] = ' ';
}

/* Obt‚m a sua jogada */
void get_player_move(void)
{
  int x, y;

  printf("Entre com as coordenadas para o X: ");
  scanf("%d%d", &x, &y);
  x--; y--;
  if(matrix[x][y]!=' ') {
    printf("Posi‡ao inv lida, tente novamente. \n");
    get_player_move();
  }
  else matrix[x][y] = 'X';
}

/* Obt‚m uma jogada do computador */
void get_computer_move(void)
{
  int i, j;

  for(i=0; i<3; i++) {
    for(j=0; j<3; j++)
      if(matrix[i][j]==' ') break;
    if(matrix[i][j]==' ') break;
  }
  if(i*j==9) {
    printf("empate\n");
    exit(0);
  }
  else
    matrix[i][j] = 'O';
}

/* Mostra a matriz na tela */
void disp_matrix(void)
{
  int t;

  for(t=0; t<3; t++) {
    printf(" %c | %c | %c ", matrix[t][0], matrix[t][1],
         matrix[t][2]);
    if(t!=2) printf("\n---|---|---\n");
  }
  printf("\n");
}

/* Verifica se h  um vencedor */
char check(void)
{
  int i;

  for(i=0; i<3; i++) /* verifica as linhas */
    if(matrix[i][0]==matrix[i][1] &&
       matrix[i][0]==matrix[i][2]) return matrix[i][0];

  for(i=0; i<3; i++) /* verifica as colunas */
    if(matrix[0][i]==matrix[1][i] &&
       matrix[0][i]==matrix[2][i]) return matrix[0][i];

  /* testa as diagonais */
  if(matrix[0][0]==matrix[1][1] &&
     matrix[1][1]==matrix[2][2])
       return matrix[0][0];

  if(matrix[0][2]==matrix[1][1] &&
     matrix[1][1]==matrix[2][0])
       return matrix[0][2];
  return ' ';
}
