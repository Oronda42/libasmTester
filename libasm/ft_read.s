section .text
    global _ft_read
    extern __errno_location

_ft_read:
    ; Arguments:
    ; rdi = file descriptor
    ; rsi = buffer
    ; rdx = count
    mov rax, 0        ; syscall number for sys_read
    syscall             ; Call the kernel
    test rax, rax
    js .error            ; Jump if return value is negative

    ret   
    
.error:
    neg rax              ; Negate the error code to make it positive
    mov rdi, rax         ; Move the error code to rdi (first argument)
    call __errno_location WRT ..plt ; Call ___errno_location to get the address of errno
    mov [rax], rdi        ; Store the error code in errno
    mov rax, -1           ; Restore the original negative error code
    ret 