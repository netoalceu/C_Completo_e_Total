	.286p
	ifndef	??version
?debug	macro
	endm
publicdll macro	name
	public	name
	endm
$comm	macro	name,dist,size,count
	comm	dist name:BYTE:count*size
	endm
	else
$comm	macro	name,dist,size,count
	comm	dist name[size]:BYTE:count
	endm
	endif
	?debug	V 300h
	?debug	S "funcoes.c"
	?debug	C E90765441F0966756E636F65732E63
_TEXT	segment byte public 'CODE'
_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:_TEXT,ds:DGROUP
_DATA	segment word public 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public 'BSS'
b@	label	byte
b@w	label	word
_BSS	ends
_TEXT	segment byte public 'CODE'
   ;	
   ;	void main(void)
   ;	
	assume	cs:_TEXT
_main	proc	near
	enter	2,0
   ;	
   ;	{
   ;	  int x;
   ;	
   ;	  x = max(10, 20);
   ;	
; *********************************************************
; Este Ç o comeáo da seqÅància de chamada.
; *********************************************************
	push	20
	push	10
	call	near ptr _max
; *********************************************************
;
;
; *********************************************************
; A pr¢xima linha faz parte da seqÅància de retorno.
; *********************************************************
	add	sp,4
	mov	word ptr [bp-2],ax
   ;	
   ;	}
   ;	
	leave	
	ret	
_main	endp
   ;	
   ;	max(int a, int b)
   ;	
	assume	cs:_TEXT
_max	proc	near
; *********************************************************
; Mais da seqÅància de chamada.
; *********************************************************
	push	bp
	mov	bp,sp
	mov	dx,word ptr [bp+4]
	mov	bx,word ptr [bp+6]
; *********************************************************
   ;	
   ;	{
   ;	  return a>b ? a : b;
   ;	
	cmp	dx,bx
	jle	short @2@86
	mov	ax,dx
	jmp	short @2@114
@2@86:
; *********************************************************
; Aqui est† a primeira parte da seqÅància de retorno.
; *********************************************************
	mov	ax,bx
@2@114:
	jmp	short @2@142
@2@142:
   ;	
   ;	}
   ;	
	pop	bp
	ret	
_max	endp
	?debug	C E9
	?debug	C FA00000000
_TEXT	ends
_DATA	segment word public 'DATA'
s@	label	byte
_DATA	ends
_TEXT	segment byte public 'CODE'
_TEXT	ends
	public	_main
	public	_max
_s@	equ	s@
	end

