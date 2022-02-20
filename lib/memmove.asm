section .text
global my_memmove

my_memmove:
  push rbp
  mov rbp, rsp
; store stack pointer to rbx so we can incremented it later
  mov rbx, rbp
  mov rax, rsi
  mov rcx, 0

; memmove allocates to a buffer before copying
; we will allocate to the stack 
stack_loop:
  mov bl, [rsi]
  push rbx
  inc rsi
  inc rcx
  cmp rcx, rdx
  jne stack_loop

  mov rcx, 0

; now we copy from the stack to destination buffer
loop:
  mov bl, [rbx]
  mov [rdi], bl
  inc rbx
  inc rdi
  inc rcx
  cmp rcx, rdx
  jne loop

  mov rsp, rbp
  pop rbp
  ret
