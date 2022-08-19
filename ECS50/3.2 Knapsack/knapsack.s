.global knapsack
.equ ws, 4
.text

knapsack:
.equ num_locals, 2
.equ weights, 2*ws #(%ebp)
.equ values, 3*ws #(%ebp)
.equ num_items, 4*ws #(%ebp)
.equ capacity, 5*ws #(%ebp)
.equ cur_value, 6*ws #(%ebp)
.equ i, -1*ws #(%ebp)
.equ best_value, -2*ws #(%ebp)

prologue:
  push %ebp
  movl %esp, %ebp
  subl $(num_locals) * ws, %esp

  movl $0, %ecx #ecx = i
  movl cur_value(%ebp), %edx #edx = cur_value
	movl %edx, best_value(%ebp) #unsigned int best_value = cur_value;

  for_start:
    cmpl num_items(%ebp), %ecx
    jae epilogue

    movl capacity(%ebp), %eax #eax = capacity
		movl weights(%ebp), %edx #edx = weights
    movl (%edx, %ecx, ws), %edx #%edx = weights[i]
    cmpl %edx, %eax #if(capacity - weights[i] >= 0 ){
    jge next
    jmp skip

    next: #best_value = max(best_value, knapsack(weights + i + 1, values + i + 1, num_items - i - 1, capacity - weights[i], cur_value + values[i]));

    movl cur_value(%ebp), %eax  #eax = cur_value
    movl values(%ebp), %edx #edx = values
    movl (%edx, %ecx, ws), %edx #edx = values[i]
    addl %edx, %eax #eax = cur_value + values[i]
    push %eax

    movl capacity(%ebp), %eax #eax = capacity
    movl weights(%ebp), %edx #edx = weights
    movl (%edx, %ecx, ws), %edx #edx = weights[i]
    subl %edx, %eax #eax = capacity - weights[i]
    push %eax

    movl num_items(%ebp), %eax #eax = num_items
    subl %ecx, %eax #eax = num_items - i
    decl %eax #eax = num_items - i - 1
    push %eax

    movl values(%ebp), %eax #eax = values
    leal ws(%eax, %ecx, ws), %eax #eax = values + i + 1
    push %eax

    movl weights(%ebp), %eax #eax = weights
    leal ws(%eax, %ecx, ws), %eax #eax = weights + i + 1
    push %eax
    movl %ecx, i(%ebp)

    call knapsack

    movl i(%ebp), %ecx

    addl $5*ws, %esp

    movl best_value(%ebp), %edx #edx = best_value
    cmpl %eax, %edx #max(best_value, knapsack(...))
    ja maxB
    jmp maxA

    maxB:
    movl %edx, best_value(%ebp)
    movl %edx, %eax
    jmp skip

    maxA:
    movl %eax, best_value(%ebp)
    jmp skip

    skip:
    incl %ecx #i++
    jmp for_start
  for_end:

  epilogue:
  	movl best_value(%ebp), %eax
  	movl %ebp, %esp
  	pop %ebp
  	ret
