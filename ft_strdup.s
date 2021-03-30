%ifdef LINUX
%define STRDUP_NAME ft_strdup
%define MALLOC_NAME malloc
%endif

%ifdef MAC
%define STRDUP_NAME _ft_strdup
%define MALLOC_NAME _malloc
%endif

global STRDUP_NAME

extern STRLEN_NAME
extern STRCPY_NAME
extern MALLOC_NAME

section .text
STRDUP_NAME:
	push	rdi
	call STRLEN_NAME
	inc rax
	mov rdi, rax
	call MALLOC_NAME
	pop rdi
	mov rsi, rdi
	mov rdi, rax
	call STRCPY_NAME
	ret
