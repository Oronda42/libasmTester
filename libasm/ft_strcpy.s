section .text
    global _ft_strcpy

_ft_strcpy:
       push rdi
    .copy_loop:
        mov al, [rsi]       ; Load byte from source
        mov [rdi], al       ; Store byte to destination
        inc rsi             ; Increment source pointer
        inc rdi             ; Increment destination pointer
        test al, al         ; Check if byte is null terminator
        jnz .copy_loop      ; If not, continue loop
        
      
    mov rax, [rsp]
    pop rdi        ; Move destination pointer to rax
    ret
