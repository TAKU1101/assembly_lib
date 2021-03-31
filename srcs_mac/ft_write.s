  
global _ft_write
extern ___error

section .text
_ft_write:
	mov rax, 0x2000004
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
	call ___error
	mov  QWORD [RAX], 22
	mov  rax, -1
	mov  rsp, rbp
	pop  rbp
	ret
.address_err:
	push rbp
	mov  rbp, rsp
	call ___error
	mov  QWORD [RAX], 14
	mov  rax, -1
	mov  rsp, rbp
	pop  rbp
	ret
.fd_err:
	push rbp
	mov  rbp, rsp
	call ___error
	mov  QWORD [RAX], 9
	mov  rax, -1
	mov  rsp, rbp
	pop  rbp
	ret