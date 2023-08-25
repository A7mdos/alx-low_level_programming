	global main
	extern printf


	section  .text

main:
	mov rdi, hel
	xor rax, rax
	call printf
	xor rax, rax
	ret


	section  .data

hel: db `Hello, Holberton`, 10