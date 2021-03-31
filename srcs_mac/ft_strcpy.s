%ifdef LINUX
%define STRCPY_NAME ft_strcpy
%endif

%ifdef MAC
%define STRCPY_NAME _ft_strcpy
%endif

global STRCPY_NAME

section .text
STRCPY_NAME:
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
