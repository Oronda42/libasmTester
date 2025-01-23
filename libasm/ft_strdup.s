section .text
    global _ft_strdup
    extern malloc
    extern _ft_strlen
    extern _ft_strcpy

_ft_strdup:
    ; Save registers
    push rdi

    call _ft_strlen     ; Call _ft_strlen
    add rax, 1          ; Add 1 to the length for the null terminator

    ; Allocate memory for the new string
    mov rdi, rax        ; Set the length as the argument for malloc
    call malloc  WRT ..plt       ; Call malloc
    test rax, rax       ; Check if malloc returned NULL
    jz .malloc_failed   ; If NULL, jump to malloc_failed

    ; Copy the input string to the newly allocated memory
    mov rsi, [rsp]        ; Set the input string as the source for _ft_strcpy
    mov rdi, rax        ; Set the allocated memory as the destination for _ft_strcpy
    call _ft_strcpy     ; Call _ft_strcpy

    ; Restore registers and return
   
    pop rdi
    ret

.malloc_failed:
    ; Restore registers and return NULL
    xor rax, rax        ; Set rax to NULL
    pop rdi
    ret