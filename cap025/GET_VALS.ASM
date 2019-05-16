; File get_val.c
; Line 6
_main:
	push	bp
	mov	bp,sp
	mov	ax,OFFSET L00184
	call	__aNchkstk
	push	si
	push	di
; a = fffc
; Line 7
; Line 9
	lea	ax,WORD PTR -4[bp]
	push	ax
	call	_get_val
	add	sp,OFFSET 2
; Line 10
	push	WORD PTR -4[bp]
	mov	ax,OFFSET L00180
	push	ax
	call	_printf
	add	sp,OFFSET 4
; Line 11
; Line 11
L00178:
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	OFFSET 0
; Line 14
; x = 0004
_get_val:
	push	bp
	mov	bp,sp
	mov	ax,OFFSET L00186
	call	__aNchkstk
	push	si
	push	di
; Line 15
	mov	bx,WORD PTR 4[bp]
	mov	WORD PTR [bx],OFFSET 100
; Line 16
; Line 16
L00183:
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	OFFSET 0
