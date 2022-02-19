section .text
global my_memcpy

my_memcpy:
  push rbp
  mov rbp, rsp
  mov rax, rsi
  mov rcx, 0

loop:
  mov bl, [rsi]
  mov [rdi], bl
  inc rdi
  inc rsi
  inc rcx
  cmp rcx, rdx
  jne loop

  mov rsp, rbp
  pop rbp
  ret
