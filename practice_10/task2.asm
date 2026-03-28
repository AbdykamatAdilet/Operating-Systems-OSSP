section .data
    msg db 'Computer Architecture & Operating Systems!', 10, 13, 0
    msgLen equ $ - msg - 1

section .text
    extern GetStdHandle
    extern WriteFile
    extern ExitProcess
    global _start

_start:
    push -11
    call GetStdHandle
    mov ebx, eax

    push 0
    push 0
    push msgLen
    push msg
    push ebx
    call WriteFile

    
    push 0
    call ExitProcess
