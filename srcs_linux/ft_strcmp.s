global ft_strcmp

section .text
ft_strcmp:
	mov rcx, 0
	mov rax, 0
	mov rdx, 0
.loop:
	mov al, byte [rdi+rcx]
	mov dl, byte [rsi+rcx]
	cmp al, 0
	je .end
	cmp dl, 0
	je .end
	cmp al, dl
	jne .end
	inc rcx
	jmp .loop
.end:
	sub rax, rdx
	ret
