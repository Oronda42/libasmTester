section .text
    global _ft_strlen

_ft_strlen:
    xor rax, rax            ; init count to 0

_loop:
    mov dl,  [rdi + rax]    ; Move the byte at address (rdi + rax) into the DL register
    test dl, dl             ; Test if the byte is 0 (null terminator)
    jz _end                 ; If zero, jump to _end
    inc rax                 ; Increment the count
    jmp _loop               ; Repeat the loop

_end:
    ret                     ; Return, rax already contains the count