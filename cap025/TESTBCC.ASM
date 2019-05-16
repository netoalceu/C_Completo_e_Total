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
	?debug	S "test.c"
	?debug	C E9878D421F06746573742E63
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
   ;	  sum = add(10, 12);
   ;	
	mov	ax,12
	push	ax
	mov	ax,10
	push	ax
	call	near ptr _add
	pop	cx
	pop	cx
	mov	word ptr DGROUP:_sum,ax
   ;	
   ;	}
   ;	
	pop	bp
	ret	
_main	endp
   ;	
   ;	add(int a, int b)
   ;	
	assume	cs:_TEXT
_add	proc	near
	push	bp
	mov	bp,sp
	sub	sp,2
   ;	
   ;	{
   ;	  int t;
   ;	
   ;	  t = a+b;
   ;	
	mov	ax,word ptr [bp+4]
	add	ax,word ptr [bp+6]
	mov	word ptr [bp-2],ax
   ;	
   ;	  return t;
   ;	
	mov	ax,word ptr [bp-2]
	jmp	short @2@58
@2@58:
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
_add	endp
_TEXT	ends
_BSS	segment word public 'BSS'
_sum	label	word
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
	public	_add
	public	_sum
_s@	equ	s@
	end
