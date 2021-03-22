global _ft_strcpy

section .text
_ft_strcpy:
	mov rax, rdi
	mov rcx, 0
.loop:
	mov al, byte [rsi + rcx]
	mov byte [rdi + rcx], al
	inc rcx
	cmp byte [rsi + rcx], 0
	je .end
	jmp .loop
.end:
	mov rax, rdi
	ret
