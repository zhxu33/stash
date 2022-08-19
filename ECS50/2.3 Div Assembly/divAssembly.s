.global _start #gdb –tui divAssembly.out

.data
  dividend:
    .long 4294967295
  divisor:
    .long 113
  i:
    .byte 31

  .text

  _start:
    movl $0, %eax # quotient
    movl $0, %edx # remainder
    movl $1, %ebx # temp val
    movl $1, %esi # found var
    movl dividend, %edi #temp dividend

  for_start: #for (int i = 31; i >= 0; i--) {
    cmpb $0, i # end loop cond
    jl for_end

    cmpl $0, %esi # if found skip to calculate
    jle calculate

    movb i, %cl #finding size
    movl $1, %ebx
    shl %cl, %ebx
    and %ebx, %edi
    cmpl $0, %edi
    ja found
    jmp skip

    found:
      sub $1, %esi
      #add $1, i
      jmp for_start

    calculate:
      movb $1, %cl
      movl $1, %ebx
      shl %cl, %edx # remainder << 1

      movb i, %cl #condition for remainder
      movl $1, %ebx # temp val
      shl %cl, %ebx
      and %ebx, %edi
      cmpl $0, %edi
      ja remainderOne
      jmp compareDivisor

      remainderOne:
        movb $0, %cl
        movl $1, %ebx
        shl %cl, %ebx
        or %ebx, %edx
        jmp compareDivisor

      compareDivisor:
      movl divisor, %ebx
      cmpl %ebx, %edx # if remainder >= divisor
      jb skip
      sub divisor, %edx
      movb i, %cl
      movl $1, %ebx
      shl %cl, %ebx
      or %ebx, %eax

    skip:
      sub $1, i
      movl dividend, %edi
      jmp for_start

  for_end:

  done:
    nop
