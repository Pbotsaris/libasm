section .text
global my_strchr

my_strchr:
  push rbp  
  mov rbp, rsp 
  mov rax, 0

loop:
  cmp  [rdi], sil 
  je found_letter 

back:
  inc rdi
  cmp [rdi], byte 0
  jne loop

  mov rsp, rbp  
  pop rbp
  ret

found_letter:
  mov rax, rdi
  jmp back
