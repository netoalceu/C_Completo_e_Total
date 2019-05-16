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
	?debug	S "regvars.c"
	?debug	C E90364441F09726567766172732E63
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
	push	bp
	mov	bp,sp
   ;	
   ;	{
   ;	  register int i;
   ;	
   ;	  for(i=0; i<100; i++) ;
   ;	
; ***************************************************
; O c¢digo seguinte inicializa a repeti‡„o controlada
; por vari vel registrador. Note como a vari vel de
; controle ‚ inicializada com uma instru‡„o XOR.
; ***************************************************
	xor	ax,ax
	jmp	short @1@86
@1@58:
; ******* Este ‚ um incremento de registrador.
	inc	ax
@1@86:
; ******* Esta ‚ uma compara‡„o de registrador.
	cmp	ax,100
	jl	short @1@58
   ;	
   ;	
   ;	  for(j=0; j<100; j++) ;
   ;	
; ***************************************************
; O c¢digo seguinte inicializa a repeti‡„o controlada
; por vari vel de mem¢ria. Note que ‚ necess rio um
; acesso a mem¢ria para inicializar a vari vel.
; ***************************************************
	mov	word ptr DGROUP:_j,0
	jmp	short @1@170
@1@142:
; ******* Aqui, um acesso a mem¢ria ‚ usado para incrementar j.
	inc	word ptr DGROUP:_j
@1@170:
; ******* Aqui, um acesso a mem¢ria ‚ usado para comparar j.
	cmp	word ptr DGROUP:_j,100
	jl	short @1@142
   ;	
   ;	}
   ;	
	pop	bp
	ret	
_main	endp
_TEXT	ends
_BSS	segment word public 'BSS'
_j	label	word
	db	2 dup (?)
	?debug	C E9
	?debug	C FA00000000
_BSS	ends
_DATA	segment word public 'DATA'
s@	label	byte
_DATA	ends
_TEXT	segment byte public 'CODE'
_TEXT	ends
	public	_main
	public	_j
_s@	equ	s@
	end

