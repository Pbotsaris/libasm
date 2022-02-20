section .text
global my_index

my_index:
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

  cmp sil, byte 0 ; index will return if find the null chars as well
  je found_null

exit:
  mov rsp, rbp  
  pop rbp
  ret

found_letter:
  mov rax, rdi
  jmp back

found_null:
  mov rax, rdi
  jmp exit
