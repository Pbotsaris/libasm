section .text
global my_strlen

my_strlen:
  push rbp  ; push stack pointer to stack
  mov rbp, rsp ; store stack pointer to the rbp register   
  mov rax, 0    

loop:
  inc rax
  inc rdi
  cmp [rdi], byte 0
  jne loop

close:
  mov rsp, rbp  ; restore stack pointer
  pop rbp
  ret





    

