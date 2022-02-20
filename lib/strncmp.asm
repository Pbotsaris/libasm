section .text

global my_strncmp

my_strncmp:
  push rbp
  mov rbp, rsp
  mov rax, 0
  mov rbx, 0
  mov rcx, 0
  mov r10, 0

loop:
  mov bl, [rdi]
  mov cl, [rsi]

  cmp bl, cl
  jne different
  
  inc r10
  inc rdi
  inc rsi
  cmp rdx, r10
  jne loop
    
  jmp close

different:
  sub ebx, ecx 
  mov eax, ebx
  jmp close

close:
  mov rsp, rbp
  pop rbp
  ret
