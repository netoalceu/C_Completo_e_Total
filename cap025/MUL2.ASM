; File mul.c
; Line 2
; a = 0004
; b = 0006
_mul:
	push	bp
	mov	bp,sp
	mov	ax,OFFSET L00106
	call	__aNchkstk
	push	si
	push	di
; Aqui é onde a multiplicação realmente acontece.
	mov	ax,word ptr [bp+4]
	imul	word ptr [bp+6]
; AX agora contém o resultado, portanto retorne.
L00105:
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	OFFSET 0
