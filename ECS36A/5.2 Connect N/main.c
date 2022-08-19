#include <stdio.h>
#include "connectn.h"

int main(int argc, char **argv) {
    int row;
    int col; 
    int neededWin;
    
    readArgs(&row, &col, &neededWin, argc, argv);
    
    char **board = createBoard(row, col);
    int player = 1;
    int selectedCol = 0; 
    int winner = 0;
    
    printBoard(board, row, col);
    while (!gameWon(board, &winner, neededWin, row, col) && !tieGame(board, row, col)) {
        getPlay(&selectedCol, row, col);
        while (!playIsValid(board, selectedCol, row, col)) {
            getPlay(&selectedCol, row, col);
        }
        playGame(board, selectedCol, &player, row, col);
        printBoard(board, row, col);
    }
    
    gameOver(winner, tieGame(board, row, col));
    destroyBoard(&board, row, col);
    
    return 0;
}
