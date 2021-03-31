global _ft_strcpy

section .text
_ft_strcpy:
	push rdi
	push rsi
	mov rcx, 0
.loop:
	cmp byte [rsi], 0
	je .end
	mov al, byte [rsi]
	mov byte [rdi], al
	inc rdi
	inc rsi
	jmp .loop
.end:
	mov al, byte [rsi]
	mov byte [rdi], al
	pop rsi
	pop rax
	ret