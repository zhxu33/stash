#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "connectn.h"

void readArgs(int* row, int* col, int* neededWin, int argc, char **argv) {
    if (argc == 4) {
        *row = atoi(argv[1]);
        *col = atoi(argv[2]);
        *neededWin = atoi(argv[3]);
    } else if (argc < 4) {
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    } else if (argc > 4) {
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
} 

char** createBoard(int row, int col) {
    char **board = (char**)malloc(sizeof(char*)*row);
	for (int i=0; i<row; ++i) {
	    board[i] = (char*)malloc(sizeof(char)*(col+1));
	}
	for (int i=0; i<row; ++i) {
	    for (int j=0; j<col; ++j) {
	        board[i][j] = '*';
	    }
	    board[i][col+1] = '\0';
	}
	return board;
}

void playGame(char** board, int selectedCol, int* player, int row, int col) {
    if (*player==1) {
        for (int i=row-1; i>=0; --i) {
            if (board[i][selectedCol] == '*') {
                board[i][selectedCol] = 'X';
                break;
            }
        }
        *player = 2;
    } else if (*player==2) {
        for (int i=row-1; i>=0; --i) {
            if (board[i][selectedCol] == '*') {
                board[i][selectedCol] = 'O';
                break;
            }
        }
        *player = 1;
    }
}

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character); 
		if(!isspace(character)){ 
			formatIsGood = false;
		}
	}while(character != '\n'); 
  return formatIsGood;
}

int getValidInt(){
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    numArgsRead = scanf(" %d", &num);
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

bool inbetween(int val, int lowerBound, int upperBound){
    //class drive code
  return val >= lowerBound && val <= upperBound;
}

int getValidIntInRange(int lowerBound, int upperBound){
    //class drive code
  int num;
  do{
    printf("Enter a column between 0 and %d to play in: ", upperBound);
    num = getValidInt();
  }while(!(inbetween(num, lowerBound, upperBound)));

  return num;
}

void getPlay(int* selectedCol, int row, int col) {
    *selectedCol = getValidIntInRange(0, col-1);
}

bool playIsValid(char** board, int selectedCol, int row, int col) {
    int valid = false;
    for (int i=0; i<col; ++i) {
        if (board[i][selectedCol] == '*') {
            valid = true;
            break;
        }
    }
    return valid;
}

bool rowWin(char**board, int* winner, int neededWin, int row, int col) {
    for (int i=0; i<row; ++i) {
	    for (int j=0; j<col; ++j) {
	        char type = board[i][j];
	        bool found = true;
	        bool found2 = true;
	        for (int k=1; k<neededWin; ++k) {
	            if (j+k<col) {
	                if (board[i][j+k] != type) {
	                    found = false;
	                    break;
	                } 
	            } else {
	                found = false;
	                break;
	            }
	        }
	        for (int k=1; k<neededWin; ++k) {
	            if (j-k>=0) {
	                if (board[i][j-k] != type) {
	                    found2 = false;
	                    break;
	                }
	            } else {
	                found2 = false;
	                break;
	            }
	        }
	        if (type == '*') {
	            found = false;
	            found2 = false;
	        }
	        if (found || found2) {
	            if (type == 'X') {
	                *winner = 1;
	            } else if (type == 'O') {
	                *winner = 2;
	            }
	            return true;
	        }
	    }
	}
	return false;
}

bool colWin(char**board, int* winner, int neededWin, int row, int col) {
    for (int i=0; i<row; ++i) {
	    for (int j=0; j<col; ++j) {
	        char type = board[i][j];
	        bool found = true;
	        bool found2 = true;
	        for (int k=1; k<neededWin; ++k) {
	            if (i+k<row) {
	                if (board[i+k][j] != type) {
	                    found = false;
	                    break;
	                } 
	            } else {
	                found = false;
	                break;
	            }
	        }
	        for (int k=1; k<neededWin; ++k) {
	            if (i-k>=0) {
	                if (board[i-k][j] != type) {
	                    found2 = false;
	                    break;
	                }
	            } else {
	                found2 = false;
	                break;
	            }
	        }
	        if (type == '*') {
	            found = false;
	            found2 = false;
	        }
	        if (found || found2) {
	            if (type == 'X') {
	                *winner = 1;
	            } else if (type == 'O') {
	                *winner = 2;
	            }
    	        return true;
	        }
	    }
	}
	return false;
}

bool diagWin(char**board, int* winner, int neededWin, int row, int col) {
    for (int i=0; i<row; ++i) {
	    for (int j=0; j<col; ++j) {
	        char type = board[i][j];
	        bool found = true;
	        bool found2 = true;
	        bool found3 = true;
	        bool found4 = true;
	        for (int k=1; k<neededWin; ++k) {
	            if (i+k<row && j+k<col) {
	                if (board[i+k][j+k] != type) {
	                    found = false;
	                    break;
	                }
	            } else {
	               found = false;
	               break;
	            }
	        }
	        for (int k=1; k<neededWin; ++k) {
	            if (i-k>=0 && j-k>=0) {
	                if (board[i-k][j-k] != type) {
	                    found2 = false;
	                    break;
	                }
	            } else {
	               found2 = false;
	               break;
	            }
	        }
	        for (int k=1; k<neededWin; ++k) {
	            if (i+k<row && j-k>=0) {
	                if (board[i+k][j-k] != type) {
	                    found3 = false;
	                    break;
	                }
	            } else {
	               found3 = false;
	               break;
	            }
	        }
	        for (int k=1; k<neededWin; ++k) {
	            if (i-k>=0 && j+k<col) {
	                if (board[i-k][j+k] != type) {
	                    found4 = false;
	                    break;
	                }
	            } else {
	               found4 = false;
	               break;
	            }
	        }
	        if (type == '*') {
	            found = false;
	            found2 = false;
	            found3 = false;
	            found4 = false;
	        }
	        if (found || found2 || found3 || found4) {
	            if (type == 'X') {
	                *winner = 1;
	            } else if (type == 'O') {
	                *winner = 2;
	            }
	            return true;
	        }
	    }
	}
	return false;
}

bool tieGame(char** board, int row, int col) {
    bool found = true;
    for (int i = 0; i < row; ++i) {
       for (int k = 0; k < col; ++k) { 
           if (board[i][k] == '*') {
               found = false;
           }
       }
    }
    return found;
}

bool gameWon(char** board, int* winner, int neededWin, int row, int col) {
    if (colWin(board, winner, neededWin, row, col) || rowWin(board, winner, neededWin, row, col) || diagWin(board, winner, neededWin, row, col)) {
        return true;
    } 
    return false;
}

void gameOver(int winner, bool tie) {
    if (winner != 0) {
        printf("Player %d Won!\n", winner);
    } else if (tie) {
        printf("Tie game!\n");
    } 
}

void printBoard(char** board, int row, int col) {
	for (int i = 0; i < row; ++i) {
	   printf("%d ", row-i-1);
       for (int k = 0; k < col; ++k) { 
       printf("%c ", board[i][k]);
       }
       printf("\n");
    }
    printf("  ");
    for (int i=0; i<col; ++i) {
        printf("%d ", i);
    }
    printf("\n");
}

void destroyBoard(char*** board, int row, int col) {
	for (int i = 0; i < row; ++i) {
       free((*board)[i]);
    }
    free(*board);
}
