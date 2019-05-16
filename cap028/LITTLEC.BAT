cl -c parser.c
cl -c lclib.c
cl littlec.c parser.obj lclib.obj /F 6000
