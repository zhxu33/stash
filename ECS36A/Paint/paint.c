#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "paint.h"

void readArgs(int* row, int* col, int argc, char **argv) {
     if (argc == 1) {
        *row = 10;
        *col = 10;
        return;
     } else if (argc != 3) { 
        printf("Wrong number of command line arguements entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        *row = 10;
        *col = 10;
        printf("Making default board of 10 X 10.\n");
        return;
    } else {
        if (atoi(argv[1]) == 0) {
            if (isdigit(*argv[1])) {
                printf("The number of rows is less than 1.\n");
            } else {
                printf("The number of rows is not an integer.\n");
            }
            *row = 10;
            *col = 10;
            printf("Making default board of 10 X 10.\n");
            return;
        } else {
            *row = atoi(argv[1]);
            if ((*row) < 1) {
            printf("The number of rows is less than 1.\n");
            *row = 10;
            *col = 10;
            printf("Making default board of 10 X 10.\n");
            return;
            }
        }
        if (atoi(argv[2]) == 0) {
            if (isdigit(*argv[2])) {
                printf("The number of columns is less than 1.\n");
            } else {
                printf("The number of columns is not an integer.\n");
            }
            *row = 10;
            *col = 10;
            printf("Making default board of 10 X 10.\n");
            return;
        } else {
            *col = atoi(argv[2]);
            if ((*col) < 1) {
            printf("The number of columns is less than 1.\n");
            *row = 10;
            *col = 10;
            printf("Making default board of 10 X 10.\n");
            return;
            }
        }
    }
} 

Board makeBoard(int row, int col) {
    Board board;
    board.row = row;
    board.col = col;
    board.arr = (char**)malloc(sizeof(char*)*row);
    for (int i=0; i<board.row; ++i) {
	    board.arr[i] = (char*)malloc(sizeof(char)*(board.col));
	}
	for (int i=0; i<board.row; ++i) {
	    for (int j=0; j<board.col; ++j) {
	        board.arr[i][j] = '*';
	    }
	}
	return board;
} 

void printBoard(Board board) {
	for (int i = 0; i < board.row; ++i) {
	   printf(" %d ", board.row-i-1);
       for (int k = 0; k < board.col; ++k) { 
       printf(" %c ", board.arr[board.row-i-1][k]);
       }
       printf("\n");
    }
    printf("   ");
    for (int i=0; i<board.col; ++i) {
        printf(" %d ", i);
    }
    printf("\n");
}

void quit(Board *board) {
    for (int i = 0; i < board->row; ++i) {
       free(board->arr[i]);
    }
    free(board->arr);
    board->arr = NULL;
}

void print_help(){

  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
}

void changeChar(Board board, int row, int col, char type) {
    if (board.arr[row][col] != '*' && board.arr[row][col] != type) {
        board.arr[row][col] = '+';
    } else {
        board.arr[row][col] = type;
    }
}

void write(Board board, int startRow, int startCol, int endRow, int endCol) {
    if (!(startRow < board.row && startCol < board.col && endRow < board.row && endCol < board.col) || startRow < 0 || startCol < 0 || endRow < 0 || endCol < 0) {
        printf("Improper draw command.\n");
        printBoard(board);
        return;
    }
    if (startRow == endRow && startCol == endCol) {
        changeChar(board, startRow, startCol, '-');
    } else if (abs(startRow-endRow) == abs(startCol-endCol)) {
        int k;
        if (startRow < endRow) {
            if (startCol < endCol) {
                k = startCol;
                for (int i=startRow; i<=endRow; i++) {
                    changeChar(board, i, k, '/');
                    k++;
                }
            } else {
                k = endCol;
                for (int i=endRow; i>=startRow; i--) {
                    changeChar(board, i, k, '\\');
                    k++;
                }
            }
        } else {
            if (startCol < endCol) {
                k = endCol;
                for (int i=endRow; i<=startRow; i++) {
                    changeChar(board, i, k, '\\');
                    k--;
                }
            } else {
                k = startCol;
                for (int i=startRow; i>=endRow; i--) {
                    changeChar(board, i, k, '/');
                    k--;
                }
            }
        }
    } else if (startRow == endRow) {
        if (startCol > endCol) {
            for (int i=endCol; i<=startCol; i++) {
                changeChar(board, startRow, i, '-');
            }
        } else if (endCol > startCol) {
            for (int i=startCol; i<=endCol; i++) {
                changeChar(board, startRow, i, '-');
            }
        }
    } else if (startCol == endCol) {
        if (startRow > endRow) {
            for (int i=endRow; i<=startRow; i++) {
                changeChar(board, i, startCol, '|');
            }
        } else if (endRow > startRow) {
            for (int i=startRow; i<=endRow; i++) {
               changeChar(board, i, startCol, '|');
            }
        }
    } else {
        printf("Cannot draw the line as it is not straight.\n");
    }
    printBoard(board);
}

void erase(Board board, int row, int col) {
    if (row >= 0 && col >= 0 && row < board.row && col < board.row) {
        board.arr[row][col] = '*';
    } else {
        printf("Improper erase command.\n");
    }
    printBoard(board);
}

void add(Board *board, char type, int pos) {
    if (type == 'r' && pos >= 0 && pos <= board->row) {
        board->row = board->row + 1;
        board->arr = (char**)realloc(board->arr,sizeof(char*)*board->row);
        for (int i=0; i<board->row-1; ++i) {
	        board->arr[i] = (char*)realloc(board->arr[i],sizeof(char)*(board->col));
	    }
	    board->arr[board->row-1] = (char*)malloc(sizeof(char)*(board->col));
        for (int i=board->row-1; i>=pos; i--) {
            for (int k=0; k<board->col; k++) {
                if (i==pos) {
                    board->arr[i][k] = '*';
                } else {
                    board->arr[i][k] = board->arr[i-1][k];
                }
            }
        }
    } else if (type == 'c' && pos >= 0 && pos <= board->col) {
        board->col = board->col + 1;
        for (int i=0; i<board->row; ++i) {
	        board->arr[i] = (char*)realloc(board->arr[i],sizeof(char)*(board->col));
	        if (board->arr[i] == NULL) {
	            printf("Shit");
	        }
	    }
	    for (int i=0; i<board->row; ++i) {
    	    for (int k=board->col-1; k>=pos; --k) {
    	        if (k==pos) {
    	            board->arr[i][k] = '*';
    	        } else {
    	            board->arr[i][k] = board->arr[i][k-1];
    	        }
    	    }
	    } 
    } else {
        printf("Improper add command.\n");
    }
}

void Delete(Board *board, char type, int pos) {
    if (type == 'r' && pos >= 0 && pos < board->row) {
        board->row = board->row - 1;
        for (int i=pos; i<=board->row; i++) {
            for (int k=0; k<board->col; k++) {
                if (i==board->row) {
                    board->arr[i][k] = '*';
                } else {
                board->arr[i][k] = board->arr[i+1][k];
                }
            }
        }
        free(board->arr[board->row]);
        board->arr = (char**)realloc(board->arr,sizeof(char*)*board->row);
    } else if (type == 'c' && pos >= 0 && pos < board->col) {
        board->col = board->col - 1;
	    for (int i=0; i<board->row; ++i) {
    	    for (int k=pos; k<board->col; k++) {
                board->arr[i][k] = board->arr[i][k+1];
            }
	    } 
	   for (int i=0; i<board->row; ++i) {
	        board->arr[i] = (char*)realloc(board->arr[i],sizeof(char)*(board->col));
	    }
    } else {
        printf("Improper delete command.\n");
    }
}

void resize(Board *board, int row, int col) {
    int origrow = board->row;
    int origcol = board->col;
    if (row >= 1 && col >= 1) {
        if (row > origrow) {
            for (int i=0; i<row-origrow; i++) {
                add(board, 'r', board->row);
            }
        } else if (row < origrow) {
           for (int i=0; i<origrow-row; i++) {
                Delete(board, 'r', board->row-1);
            } 
        }
        if (col > origcol) {
            for (int i=0; i<col-origcol; i++) {
                add(board, 'c', board->col);
            }
        } else if (col < origcol) {
           for (int i=0; i<origcol-col; i++) {
                Delete(board, 'c', board->col-1);
            } 
        }
    } else {
        printf("Improper resize command.\n");
    }
    printBoard(*board);
}