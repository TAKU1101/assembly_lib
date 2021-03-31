%ifdef LINUX
%define STRLEN_NAME ft_strlen
%endif

%ifdef MAC
%define STRLEN_NAME _ft_strlen
%endif

global STRLEN_NAME

section .text
STRLEN_NAME:
	mov rax, rdi
.loop:
	cmp byte [rax], 0
	je .end
	inc rax
	jmp .loop
.end:
	sub rax, rdi
	ret
