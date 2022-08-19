.global _start #gdb –tui editDist.out
.equ ws, 4

.data
  string1:
    .space 100
  string2:
    .space 100
  string1_len:
    .long 0
  string2_len:
    .long 0
  d:
    .space 40000
  i:
    .long 0
  j:
    .long 0
  insert:
    .long 0
  delete:
    .long 0
  substitute:
    .long 0
  subval:
    .long 0

.text

_start:

  movl $0, %ebx
  len:
    movb string1(, %ebx, 1), %cl
    cmpb $0, %cl
    jle endLen
    inc %ebx
    jmp len
  endLen:
  incl %ebx
  movl %ebx, string1_len

  movl $0, %ebx
  len2:
    movb string2(, %ebx, 1), %cl
    cmpb $0, %cl
    jle endLen2
    inc %ebx
    jmp len2
  endLen2:
  incl %ebx
  movl %ebx, string2_len

  movl $1, %ebx
  for_start1:
    cmpl string2_len, %ebx
    jg for_end1
    movl %ebx, i
    movl string1_len, %eax
    imull i
    movl %ebx, d(,%eax,ws)
    incl %ebx
    jmp for_start1
  for_end1:

  movl $1, %ebx
  for_start2:
    cmpl string1_len, %ebx
    jge for_end2
    movl %ebx, d(,%ebx,ws)
    incl %ebx
    jmp for_start2
  for_end2:

  movl $1, %ebx #i
  movl $1, %esi #j
  outer_for_start:
    movl $1, %esi #j
    cmpl string2_len, %ebx
    jge outer_for_end
    inner_for_start:

      cmpl string1_len, %esi
      jge inner_for_end

      decl %esi
      decl %ebx
      movb string1(, %esi, 1), %al
      movb string2(, %ebx, 1), %cl
      incl %esi
      incl %ebx
      cmpb %al,%cl
      jz sub0
      jmp sub1

      sub0:
      movl $0, subval
      jmp next

      sub1:
      movl $1, subval

      next:

      movl %ebx, i
      movl %esi, j

      movl string1_len, %eax
      imull %ebx
      decl %esi
      addl %esi, %eax
      movl d(,%eax,ws),%ecx
      incl %ecx # insertion

      movl i, %ebx
      movl j, %esi

      decl %ebx
      movl string1_len, %eax
      imull %ebx
      addl %esi, %eax
      movl d(,%eax,ws),%edi
      incl %edi # deletion

      movl i, %ebx
      movl j, %esi

      decl %ebx
      decl %esi
      movl string1_len, %eax
      imull %ebx
      addl %esi, %eax
      movl d(,%eax,ws),%edx
      addl subval, %edx # substitution
      movl %edx, subval

      movl i, %ebx
      movl j, %esi

      movl string1_len, %eax
      imull %ebx
      addl %esi, %eax
      movl i, %ebx
      movl j, %esi
      movl subval, %edx

      cmpl %ecx, %edi
      jge compare2
      jmp compare1

      compare1:
      cmpl %edi, %edx
      jge deletion
      jmp substitution

      compare2:
      cmpl %ecx, %edx
      jge insertion
      jmp substitution

      deletion:
      movl %edi,d(,%eax,ws)
      jmp next2

      insertion:
      movl %ecx,d(,%eax,ws)
      jmp next2

      substitution:
      movl %edx, d(,%eax,ws)
      jmp next2

      next2:

      incl %esi
      jmp inner_for_start

    inner_for_end:
    incl %ebx
    jmp outer_for_start
  outer_for_end:

  movl string2_len, %ebx
  movl string1_len, %eax
  imull %ebx
  decl %eax
  movl d(,%eax,ws), %eax

done:
	nop
