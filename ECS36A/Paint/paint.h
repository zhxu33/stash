#ifndef PAINT_H
#define PAINT_H

    typedef struct Board_struct  {
       int row;
       int col;
       char **arr;
    } Board;
    void readArgs(int* row, int* col, int argc, char **argv);
	char** make_empty_arr(int row, int col);
	Board makeBoard(int row, int col);
	void printBoard(Board board);
	void quit(Board *board);
	void print_help();
	void write(Board board, int startRow, int startCol, int endRow, int endCol);
	void erase(Board board, int row, int col);
	void add(Board *board, char type, int pos);
	void Delete(Board *board, char type, int pos);
	void resize(Board *board, int row, int col);
	

#endif
