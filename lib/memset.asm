section .text

global my_memset

my_memset:
  push rbp
  mov rbp, rsp
  mov rcx, 0

loop:
  mov [rdi], sil 
  inc rdi
  inc rcx
  cmp rcx, rdx
  jne loop

  mov rsp, rbp
  pop rbp
  ret
   
