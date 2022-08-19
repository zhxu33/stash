.global _start

.data
  num1:
    .long 1
    .long 1
  num2:
    .long 1
    .long 1

  .text

  _start:
    movl num1, %edx
    addl num2, %edx
    movl num1+4, %eax
    addl num2+4, %eax
    jc add
    jmp done

  add:
      addl $1, %edx

  done:
    nop
