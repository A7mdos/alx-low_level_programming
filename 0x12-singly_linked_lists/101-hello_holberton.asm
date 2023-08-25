	global main
	extern printf

main:
	mov rdi, msg
	xor rax, rax
	call printf
	xor rax, rax
	ret

msg: db `Hello, Holberton`, 10