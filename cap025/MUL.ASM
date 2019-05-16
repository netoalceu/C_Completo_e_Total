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
; Line 3
; Line 3
L00105:
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	OFFSET 0
