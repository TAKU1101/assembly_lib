%ifdef LINUX
%define READ_NAME ft_read
%define ERROR_NAME __errno_location
%define WRITE_NUM 0x0
%endif

%ifdef MAC
%define READ_NAME _ft_read
%define ERROR_NAME ___error
%define WRITE_NUM 0x2000003
%endif

global WRITE_NAME
extern ERROR_NAME

section .text
READ_NAME:
	mov rax, 0x2000003
	syscall
	cmp rax,9
	je .fd_err
	cmp rax, 14
	je .address_err
	cmp rax, 22
	je .len_err
	ret
.len_err:
	push rbp
	mov  rbp, rsp
	call ERROR_NAME
	mov  QWORD [RAX], 22
	mov  rax, -1
	mov  rsp, rbp
	pop  rbp
	ret
.address_err:
	push rbp
	mov  rbp, rsp
	call ERROR_NAME
	mov  QWORD [RAX], 14
	mov  rax, -1
	mov  rsp, rbp
	pop  rbp
	ret
.fd_err:
	push rbp
	mov  rbp, rsp
	call ERROR_NAME
	mov  QWORD [RAX], 9
	mov  rax, -1
	mov  rsp, rbp
	pop  rbp
	ret
