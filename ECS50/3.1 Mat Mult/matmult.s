/*
int** matMult(int **a, int num_rows_a, int num_cols_a, int** b, int num_rows_b, int num_cols_b) {
	int** c = (int**)malloc(num_rows_a*sizeof(int*));
	for (int row = 0; row < num_rows_a; row++){
		c[row] = (int*)malloc(num_cols_b*sizeof(int));
		for (int col = 0; col < num_cols_b; col++) {
			c[row][col] = 0;
			for (int i = 0; i < num_cols_a; i++) {
				c[row][col] = c[row][col] + a[row][i]*b[i][col];
			}
		}
	}
	return c;
}
./matmult.out a0-test.txt b0-test.txt
gdb -tui -args matmult.out a0-test.txt b0-test.txt
*/

.global matMult
.equ ws, 4

.text

matMult:
  .equ num_locals, 4
  .equ num_extra_regs, 3
  .equ a, 2*ws #(%ebp)
  .equ num_rows_a, 3*ws #(%ebp)
  .equ num_cols_a, 4*ws  #(%ebp)
  .equ b, 5*ws #(%ebp)
  .equ num_rows_b, 6*ws #(%ebp)
  .equ num_cols_b, 7*ws #(%ebp)
  .equ c, -1*ws #(%ebp)
  .equ row, -2*ws #(%ebp)
  .equ col, -3*ws #(%ebp)
  .equ i, -4*ws #(%ebp)
  .equ old_ebx, -5*ws #(%ebp)
	.equ old_esi, -6*ws #(%ebp)
	.equ old_edi, -7*ws #(%ebp)

  prologue:
    push %ebp
    movl %esp, %ebp
    subl $(num_locals + num_extra_regs) * ws, %esp
    movl %ebx, old_ebx(%ebp)
		movl %esi, old_esi(%ebp)
		movl %edi, old_edi(%ebp)

# int** c = (int**)malloc(num_rows_a*sizeof(int));
    movl num_rows_a(%ebp), %eax #eax = num_rows_a
    shll $2, %eax #eax = num_row_a*sizeof(int*)
    push %eax # set the argument to malloc
    call malloc
    addl $1*ws, %esp # remove the argument to malloc from the stack
    movl %eax, c(%ebp)

# for (int row = 0; row < num_rows_a; row++){
# %ecx will be row

    movl $0, %ecx
    start_outer_for:
      # row < num_rows_a == row - num_rows_a < 0
      # negation row - num_rows_a >= 0
      cmpl num_rows_a(%ebp), %ecx
      jge end_outer_for

      #c[row] = (int*)malloc(num_cols_b*sizeof(int));
      movl num_cols_b(%ebp), %ebx
      shll $2, %ebx #ebx = num_cols_b*sizeof(int)
      push %ebx
      movl %ecx, row(%ebp) #save the most current value of row to memory so malloc doesnt overwrite it
      call malloc
      addl $1*ws, %esp #clear the argument to malloc
      movl row(%ebp), %ecx # restore row

      movl c(%ebp), %edx # edx = c
      movl %eax, (%edx, %ecx, ws) # c[row] = (int*)malloc(num_cols_b*sizeof(int));

      #for (int col = 0; col < num_cols_b; col++) {
      movl $0, %ebx #ebx will be col
      inner_for_start:
      cmpl num_cols_b(%ebp), %ebx
      jge inner_for_end

      #c[row][col] = 0;
      #*(*(c + row) + col) = 0
      movl $0, (%eax, %ebx, ws)

      #for (int i = 0; i < num_cols_a; i++) {
			movl $0, %esi #esi wil be i
			for_start:
				cmpl num_cols_a(%ebp), %esi
				jge for_end

				#c[row][col] = c[row][col] + a[row][i]*b[i][col];
				push %eax
				movl a(%ebp), %eax
				movl (%eax, %ecx, ws), %eax
				movl (%eax, %esi, ws), %eax
				movl b(%ebp), %edi
				movl (%edi, %esi, ws), %edi
				movl (%edi, %ebx, ws), %edi
				imull %edi
				movl %eax, %edi
				pop %eax
				addl %edi, (%eax, %ebx, ws)

				incl %esi
				jmp for_start
			for_end:

      incl %ebx
      jmp inner_for_start

      inner_for_end:

      incl %ecx #++ i
      jmp start_outer_for #next iteration
    end_outer_for:

epilogue:
	movl c(%ebp), %eax
	movl old_ebx(%ebp), %ebx
	movl old_edi(%ebp), %edi
	movl old_esi(%ebp), %esi
	movl %ebp, %esp
	pop %ebp
	ret
