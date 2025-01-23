section .text
    global _ft_strcmp

_ft_strcmp:
    xor rax, rax            ; Set return value to 0
    xor rbx, rbx            ; Clear rbx register
    .compare_loop:
        mov al, [rdi]       ; Load byte from first string
        mov bl, [rsi]       ; Load byte from second string
        cmp al, bl          ; Compare the bytes
        jne .not_equal      ; If not equal, jump to not_equal
        test al, al         ; Check if end of string (null terminator)
        jz .equal           ; If end of string, jump to equal
        inc rdi             ; Increment first string pointer
        inc rsi             ; Increment second string pointer
        jmp .compare_loop   ; Repeat the loop

    .not_equal:
        sub rax, rbx        ; Calculate the difference
        ret                 ; Return the difference

    .equal:
        xor rax, rax        ; Set return value to 0 (strings are equal)
        ret  