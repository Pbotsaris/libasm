section .text

global my_strcmp

my_strcmp:
  push rbp
  mov rbp, rsp
  mov rax, 0
  mov rbx, 0
  mov rcx, 0

outer_loop:
  mov bl, [rdi]
  mov cl, [rsi]

  cmp bl, cl
  jne different
  
  inc rdi
  inc rsi
  cmp [rdi], byte 0
  jne outer_loop

  cmp [rsi], byte 0
  jne longer
    
  jmp close

different:
  sub ebx, ecx 
  mov eax, ebx
  jmp close

longer:
  mov cl, [rsi]
  mov ebx, 0
  jmp different

close:
  mov rsp, rbp
  pop rbp
  ret
