section .data
    hello db "Hello, Holberton", 0
    format db "%s", 10, 0  ; Format string for printf: %s (string) followed by newline

section .text
    global main
    extern printf

main:
    push rbp
    mov rdi, format    ; First argument: Format string
    mov rsi, hello     ; Second argument: Pointer to the string "Hello, Holberton"
    call printf        ; Call printf function
    add rsp, 8         ; Clean up the stack
    pop rbp
    ret
