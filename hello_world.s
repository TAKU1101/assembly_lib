global _main

section	.data
msg:	db 'helloworld', 10

section	.text
_main:
	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, msg
	mov rdx, 14
	syscall

	ret
