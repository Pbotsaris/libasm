section .text

global my_write

my_write:
  push rbp
  mov rbp, rsp
  mov rax, 1 ; write syscall
  syscall

exit:
  mov rsp, rbp
  pop rbp
  ret
