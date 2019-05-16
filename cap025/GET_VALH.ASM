; File get_val.c
; Line 6
_main:
	push	bp
	mov	bp,sp
	mov	ax,OFFSET L00184
	call	FAR PTR __aFchkstk
	push	si
	push	di
; a = fffc
; Line 7
; Line 9
	lea	ax,WORD PTR -4[bp]
	mov	dx,ss
	push	dx
	push	ax
	call	FAR PTR _get_val
	add	sp,OFFSET 4
; Line 10
	push	WORD PTR -4[bp]
	mov	ax,OFFSET L00180
	mov	dx,ds
	push	dx
	push	ax
	call	FAR PTR _printf
	add	sp,OFFSET 6
; Line 11
; Line 11
L00178:
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	OFFSET 0
; Line 14
; x = 0006
_get_val:
	push	bp
	mov	bp,sp
	mov	ax,OFFSET L00186
	call	FAR PTR __aFchkstk
	push	si
	push	di
; Line 15
	les	bx,WORD PTR 6[bp]
	mov	WORD PTR es:[bx],OFFSET 100
; Line 16
; Line 16
L00183:
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	OFFSET 0
