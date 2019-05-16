; File test.c
; Line 4
_main:
	push	bp
	mov	bp,sp
	mov	ax,OFFSET L00114
	call	__aNchkstk
	push	si
	push	di
; Line 5
	mov	ax,OFFSET 12
	push	ax
	mov	ax,OFFSET 10
	push	ax
	call	_add
	add	sp,OFFSET 4
	mov	WORD PTR _sum,ax
; Line 6
; Line 6
L00107:
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	OFFSET 0
; Line 9
; a = 0004
; b = 0006
_add:
	push	bp
	mov	bp,sp
	mov	ax,OFFSET L00116
	call	__aNchkstk
	push	si
	push	di
; t = fffc
; Line 10
; Line 12
	mov	ax,WORD PTR 4[bp]
	add	ax,WORD PTR 6[bp]
	mov	WORD PTR -4[bp],ax
; Line 13
	mov	ax,WORD PTR -4[bp]
	jmp	L00112
; Line 14
; Line 14
L00112:
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	OFFSET 0
