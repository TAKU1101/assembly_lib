global _ft_read
extern ___error

section .text
_ft_read:
	push rbp
	mov  rbp, rsp
	mov rax, 0x2000003
	syscall
	push rax
	jc .error
	jmp .end
.error:
	call ___error
	pop rcx
	mov  QWORD [RAX], rcx
	mov  rax, -1
.end
	mov  rsp, rbp
	pop  rbp
	ret
