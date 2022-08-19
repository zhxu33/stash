#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "paint.h"

//./paint.out

//gdb -ex=r --args ./paint.out

//valgrind --leak-check=full --track-origins=yes ./paint.out

/* w 0 0 9 9
w 9 0 0 9
a r 3
a r 5
a c 2
a c 7
a r 8
a c 7
d c 2
d c 1
a r 2
a c 0
w 2 0 2 5
e 3 3
s something.txt
r 5 4
r 12 9
a r 2
a c 1
r 2 2
d c 1
d r 1
l something.txt
a r 3
a c 3
e 2 2
e 1 1 
e 1 2
w 0 0 0 4
r 20 20
r 15 30 
h
q
*/
 
int main(int argc, char **argv) {
    int row = 0;
    int col = 0;
    readArgs(&row, &col, argc, argv);
    Board board = makeBoard(row, col);
    printBoard(board);
    char command = '\n';
    while (command != 'q') {
        printf("Enter your command: ");
        scanf(" %c", &command);
        if (command == 'q') {
            scanf("%c", &command);
            if (command == '\n') {
                quit(&board);
                exit(0);
            } else {
                printf("Unrecognized command. Type h for help.\n");
            }
            printBoard(board);
        } else if (command == 'h') {
            scanf("%c", &command);
            if (command == '\n') {
            print_help();
            } else {
                printf("Unrecognized command. Type h for help.\n");
            }
            printBoard(board);
        } else if (command == 'w') {
            int startRow;
            int startCol;
            int endRow;
            int endCol;
            scanf(" %d %d %d %d", &startRow, &startCol, &endRow, &endCol);
            write(board, startRow, startCol, endRow, endCol);
        } else if (command == 'e') {
            int row;
            int col;
            scanf(" %d %d", &row, &col);
            erase(board, row, col);
        } else if (command == 'a') {
            char type = 'x';
            int pos = -1;
            scanf(" %c %d", &type, &pos);
            add(&board, type, pos);
            printBoard(board);
        } else if (command == 'd') {
            char type = 'x';
            int pos = -1;
            scanf(" %c %d", &type, &pos);
            Delete(&board, type, pos);
            printBoard(board);
        } else if (command == 'r') {
            int row;
            int col;
            scanf(" %d %d", &row, &col);
            resize(&board, row, col);
        } else if (command == 's') {
            char filename[100];
            scanf(" %100s", filename);
            FILE* textFile = fopen(filename, "w");
            if (textFile != NULL) {
            fprintf(textFile, "%d %d", board.row, board.col);
            for (int i=0; i<board.row; i++) {
                for (int j=0; j<board.col; j++) {
                    fprintf(textFile, "%c", board.arr[i][j]);
                }
            }
            fclose(textFile);
            } else {
                printf("Failed to open file: %s\n", filename);
            }
            printBoard(board);
        } else if (command == 'l') {
            char filename[20];
            scanf(" %20s", filename);
            FILE* textFile = fopen(filename, "r");
            if (textFile != NULL) {
            quit(&board);
            fscanf(textFile, "%d", &board.row);
            fscanf(textFile, "%d", &board.col);
            board = makeBoard(board.row, board.col);
            for (int i=0; i<board.row; i++) {
                for (int j=0; j<board.col; j++) {
                    fscanf(textFile, "%c", &board.arr[i][j]);
                }
            }
            fclose(textFile);
            } else {
                printf("Failed to open file: %s\n", filename);
            }
             printBoard(board);
        } else {
            printf("Unrecognized command. Type h for help.\n");
            printBoard(board);
        }
        while (command!='\n') { 
        scanf("%c", &command);
        }
    }
}
