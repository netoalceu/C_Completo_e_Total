/* Um esqueleto minimal Windows 95. */

#include <windows.h>

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);

char szWinName[] = "MinhaJan"; /* Nome da classe de janela */

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst,
                   LPSTR lpszArgs, int nWinMode)
{
  HWND hwnd;
  MSG msg;
  WNDCLASS wcl;

  /* Define uma classe de janela. */
  wcl.hInstance = hThisInst; /* handle desta inst�ncia */
  wcl.lpszClassName = szWinName; /* nome da classe de janela */
  wcl.lpfnWndProc = WindowFunc; /* fun��o de janela */
  wcl.style = 0; /* estilo padr�o */

  wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION); /* estilo de �cone */
  wcl.hCursor = LoadCursor(NULL, IDC_ARROW); /* estilo de cursor */
  wcl.lpszMenuName = NULL; /* sem menu */

  wcl.cbClsExtra = 0; /* nenhuma informa��o */
  wcl.cbWndExtra = 0; /* extra � necess�ria */

  /* Faz o fundo da janela ser branco. */
  wcl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);

  /* Registra a classe de janela. */
  if (!RegisterClass(&wcl)) return 0;

  /* Agora que uma classe de janela foi registrada,
     pode ser criada uma janela */
  hwnd = CreateWindow(
    szWinName, /* nome da classe da janela */
    "Esqueleto Windows 95", /* t�tulo */
    WS_OVERLAPPEDWINDOW, /* estilo da janela - normal */
    CW_USEDEFAULT, /* coordenada X - deixe Windows decidir */
    CW_USEDEFAULT, /* coordenada Y - deixe Windows decidir */
    CW_USEDEFAULT, /* largura - deixe Windows decidir */
    CW_USEDEFAULT, /* altura - deixe Windows decidir */
    HWND_DESKTOP, /* nenhuma janela pai */
    NULL, /* sem men� */ 
    hThisInst, /* handle desta inst�ncia do programa */
    NULL /* nenhum argumento adicional */
  );

  /* Exibe a janela. */
  ShowWindow(hwnd, nWinMode);
  UpdateWindow(hwnd);

  /* Cria a repeti��o de mensagens. */
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg); /* permite uso do teclado */
    DispatchMessage(&msg); /* retorna o controle ao Windows */
  }
  return msg.wParam;
}

/* Esta fun��o � chamada pelo Windows e
   recebe mensagens da fila de mensagens. 
*/
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message,
                            WPARAM wParam, LPARAM lParam)
{
  switch (message) {
    case WM_DESTROY: /* encerre o programa */
      PostQuitMessage(0);
      break;
    default:
      /* Deixe o Windows 95 processar quaisquer mensagens
         n�o especificadas no comando switch acima. */
      return DefWindowProc(hwnd, message, wParam, lParam);
  }
  return 0;
}
