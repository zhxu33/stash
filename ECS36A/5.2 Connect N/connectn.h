#ifndef CONNECTN_H
#define CONNECTN_H
#include <stdbool.h>

    void readArgs(int* row, int* col, int* neededWin, int argc, char **argv);
    char** createBoard(int row, int col);
    void playGame(char** board, int selectedCol, int* player, int row, int col);
    int getValidInt();
    int getValidIntInRange(int lowerBound, int upperBound);
    void getPlay(int* selectedCol, int row, int col);
    bool playIsValid(char** board, int selectedCol, int row, int col);
    bool isValidFormat(const int numArgsRead, const int numArgsNeed);
    bool inbetween(int val, int lowerBound, int upperBound);
    bool rowWin(char**board, int* winner, int neededWin, int row, int col);
    bool colWin(char**board, int* winner, int neededWin, int row, int col);
    bool diagWin(char**board, int* winner, int neededWin, int row, int col);
    bool tieGame(char** board, int row, int col);
    bool gameWon(char** board, int* winner, int neededWin, int row, int col);
    void gameOver(int winner, bool tie);
    void printBoard(char** board, int row, int col);
    void destroyBoard(char*** board, int row, int col);

#endif
