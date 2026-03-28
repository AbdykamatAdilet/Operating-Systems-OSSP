section .data
    nums db '1 2 3 4 5 6 7 8 9', 10, 13, 0
    numsLen equ $ - nums - 1

section .text
    extern GetStdHandle
    extern WriteFile
    extern ExitProcess
    global _start

_start:
  
    push -11
    call GetStdHandle
    mov ebx, eax

    push 0          ; lpReserved
    push 0          ; lpNumberOfBytesWritten
    push numsLen    ; nNumberOfBytesToWrite
    push nums       ; lpBuffer
    push ebx        ; hFile (handle)
    call WriteFile

    push 0
    call ExitProcess
