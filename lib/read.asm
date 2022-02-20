section .text

global my_read

my_read:
  push rbp
  mov rbp, rsp
  mov rax, 0 ; read syscall
  syscall

  mov rbx, 0 ; to increment rbx
loop:
 inc rsi ; increment the buffer pointer to add the null char
 inc rbx
 cmp rbx, rax
 jne loop ; increment pointer until size

 mov [rsi], byte 0 ; add null char

exit:
  mov rsp, rbp
  pop rbp
  ret
