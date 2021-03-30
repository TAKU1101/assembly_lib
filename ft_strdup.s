%ifdef LINUX
%define STRDUP_NAME ft_strdup
%define MALLOC_NAME malloc
%define STRLEN_NAME ft_strlen
%define STRCPY_NAME ft_strcpy
%endif

%ifdef MAC
%define STRDUP_NAME _ft_strdup
%define MALLOC_NAME _malloc
%define STRLEN_NAME _ft_strlen
%define STRCPY_NAME _ft_strcpy
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
