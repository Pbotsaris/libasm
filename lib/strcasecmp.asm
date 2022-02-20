section .text

global my_strcasecmp

my_strcasecmp:
  push rbp
  mov rbp, rsp
  mov rax, 0
  mov rbx, 0
  mov rcx, 0

loop:
  mov bl, [rdi]
  mov cl, [rsi]

check_case:
  cmp bl, byte 91 ;  Z char or less
  jl check_bl ; jumps to second condition
  cmp cl, byte 91
  jl check_cl

compare_char:
  cmp bl, cl
  jne different
  inc rdi
  inc rsi
  cmp [rdi], byte 0
  jne loop

  cmp [rsi], byte 0
  jne longer
  jmp exit

different:
  sub ebx, ecx 
  mov eax, ebx
  jmp exit

longer:
  mov cl, [rsi]
  mov ebx, 0
  jmp different

check_bl:
  cmp bl, byte 64 ; A char or greater
  jg convert_bl
  jmp compare_char

check_cl:
  cmp cl, byte 64 ; A char or greater
  jg convert_cl
  jmp compare_char

convert_bl:
  add bl, byte 32 ; offset to lowcase
  jmp compare_char

convert_cl:
  add cl, byte 32 ; offset to lowcase
  jmp compare_char

exit:
  mov rsp, rbp
  pop rbp
  ret
