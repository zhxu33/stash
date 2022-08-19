.global get_combs
.equ ws, 4

.text
get_combs:
  .equ num_locals, 7
  .equ items, 2*ws #(%ebp)
  .equ k, 3*ws #(%ebp)
  .equ len, 4*ws  #(%ebp)
  .equ numCombs, -1*ws #(%ebp)
  .equ combs, -2*ws #(%ebp)
  .equ data, -3*ws #(%ebp)
  .equ row, -4*ws #(%ebp)
  .equ i, -5*ws #(%ebp)
  .equ old_esi, -6*ws #(%ebp)
  .equ old_edi, -7*ws #(%ebp)

prologue:
  push %ebp
  movl %esp, %ebp
  subl $(num_locals) * ws, %esp
  movl %esi, old_esi(%ebp)
  movl %edi, old_edi(%ebp)

  #int numCombs = num_combs(len, k);
  push k(%ebp)
  push len(%ebp)
  call num_combs
  addl $2*ws, %esp
  movl %eax, numCombs(%ebp)

#int** combs = (int**)malloc(numCombs*sizeof(int*));
shll $2, %eax #eax = numCombs*sizeof(int*)
push %eax # set the argument to malloc
call malloc
addl $1*ws, %esp # remove the argument to malloc from the stack
movl %eax, combs(%ebp)

# int* data = (int*)malloc(k*sizeof(int));
movl k(%ebp), %eax #eax = k
shll $2, %eax #eax = k*sizeof(int)
push %eax
call malloc
addl $1*ws, %esp # remove the argument to malloc from the stack
movl %eax, data(%ebp)

#int row = 0;
movl $0, row(%ebp)

movl $0, %ecx #ecx = i
#for (int i=0; i<numCombs; i++) {
for_start5:
  cmpl numCombs(%ebp), %ecx
  jge for_end5
  #combs[i] = (int*)malloc(k*sizeof(int))
  movl %ecx, i(%ebp) #save ecx so malloc doesnt overwrite it
  movl k(%ebp), %eax #eax = k
  shll $2, %eax #eax = k*sizeof(int)
  push %eax
  call malloc
  addl $1*ws, %esp #clear the argument to malloc
  movl i(%ebp), %ecx #restore ecx
  movl combs(%ebp), %edx #edx = combs
  movl %eax, (%edx, %ecx, ws) # combs[i] = (int*)malloc(k*sizeof(int))
  incl %ecx
  jmp for_start5
for_end5:

#combination(items, len, k, 0, data, 0, combs, &row);
leal row(%ebp), %eax
push %eax
push combs(%ebp)
push $0
push data(%ebp)
push $0
push k(%ebp)
push len(%ebp)
push items(%ebp)
call combination
addl $8*ws, %esp #clear the argument

epilogue:
  movl combs(%ebp), %eax
  movl old_edi(%ebp), %edi
  movl old_esi(%ebp), %esi
	movl %ebp, %esp
	pop %ebp
	ret

combination:
  .equ arr, 2*ws #(%ebp)
  .equ n, 3*ws #(%ebp)
  .equ r, 4*ws  #(%ebp)
  .equ index, 5*ws  #(%ebp)
  .equ data, 6*ws #(%ebp)
  .equ i, 7*ws #(%ebp)
  .equ combs, 8*ws #(%ebp)
  .equ row, 9*ws #(%ebp)

#if (index == r)
push %ebp
movl %esp, %ebp
movl r(%ebp), %eax
cmpl index(%ebp), %eax
jz if
jmp skipif

if:
  movl $0, %ecx #ecx = j
  #for (int j = 0; j < r; j++) {
  for_start6:
    cmpl %eax, %ecx
    jge for_end6
    movl combs(%ebp), %esi #esi = combs
    movl row(%ebp), %edi #edi = *row
    movl (%edi), %edi
    movl data(%ebp), %edx #edx = data
    movl (%edx, %ecx, ws), %edx #edx = data[j]
    movl (%esi, %edi, ws), %esi #esi = combs[*row]
    movl %edx, (%esi, %ecx, ws) #combs[*row][j] = data[j];
    incl %ecx
    jmp for_start6
  for_end6:
  #*row = *row+1;
  movl row(%ebp), %eax #eax = row
  incl (%eax)
  movl row(%ebp), %ecx #ecx = row
  movl %eax, (%ebp, %ecx) #? #ecx = eax
  movl %ebp, %esp
  pop %ebp
  ret

skipif:
  #if (i >= n) {
  movl i(%ebp), %eax #eax = i
  movl n(%ebp), %ecx #ecx = n
  cmpl %ecx, %eax
  jge return
  jmp go

  return:
  movl %ebp, %esp
  pop %ebp
  ret

  go:
  #data[index] = arr[i];
  movl index(%ebp), %ecx #ecx = index
  movl data(%ebp), %edx #edx = data
  movl i(%ebp), %eax #eax = i
  movl arr(%ebp), %esi #esi = arr
  movl (%esi, %eax, ws), %esi #esi = arr[i]
  movl %esi, (%edx, %ecx, ws) #data[index] = arr[i]

  #combination(arr, n, r, index + 1, data, i + 1, combs, row);
  push row(%ebp)
  push combs(%ebp)
  movl i(%ebp), %eax
  incl %eax
  push %eax
  push data(%ebp)
  movl index(%ebp), %eax
  incl %eax
  push %eax
  push r(%ebp)
  push n(%ebp)
  push arr(%ebp)
  call combination
  addl $8*ws, %esp #clear the argument

  #combination(arr, n, r, index, data, i+1, combs, row);
  push row(%ebp)
  push combs(%ebp)
  movl i(%ebp), %eax
  incl %eax
  push %eax
  push data(%ebp)
  push index(%ebp)
  push r(%ebp)
  push n(%ebp)
  push arr(%ebp)
  call combination
  addl $8*ws, %esp #clear the argument
  movl %ebp, %esp
  pop %ebp
  ret
