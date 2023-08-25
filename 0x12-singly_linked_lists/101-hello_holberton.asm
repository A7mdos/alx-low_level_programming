	global main
	extern printf

main:

	mov rdi, hello
	xor rax, rax
	call printf

	xor rax, rax
	ret

hello: db `Hello, Holberton`, 10