global ft_write
extern __errno_location

section .text
ft_write:
;	cmp edi, 0
;	jl .fd_err
	mov rax, 0x1
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
	call __errno_location
	mov  QWORD [RAX], 22
	mov  rax, -1
	mov  rsp, rbp
	pop  rbp
	ret
.address_err:
	push rbp
	mov  rbp, rsp
	call __errno_location
	mov  QWORD [RAX], 14
	mov  rax, -1
	mov  rsp, rbp
	pop  rbp
	ret
.fd_err:
	push rbp
	mov  rbp, rsp
	call __errno_location
	mov  QWORD [RAX], 9
	mov  rax, -1
	mov  rsp, rbp
	pop  rbp
	ret
