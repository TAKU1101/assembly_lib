global _ft_strcmp

section .text
_ft_strcmp:
	mov rcx, 0
.loop:
	mov al, byte [rdi+rcx]
	mov dl, byte [rsi+rcx]
	cmp al, dh
	jne .end
	cmp byte [rdi+rcx], 0
	je .end
	cmp byte [rsi+rcx], 0
	je .end
	inc rcx
	jmp .loop
.end:
	sub rax, rdx
	ret
