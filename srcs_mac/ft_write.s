global _ft_write
extern ___error

section .text
_ft_write:
	push rbp
	mov  rbp, rsp
	push rcx
	mov rax, 0x2000004
	syscall
	jc .error
	jmp .end
.error:
	push rax
	call ___error
	pop rcx
	mov  QWORD [RAX], rcx
	mov  rax, -1
.end:
	pop rcx
	mov  rsp, rbp
	pop  rbp
	ret
