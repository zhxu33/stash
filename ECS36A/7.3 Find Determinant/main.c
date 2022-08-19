#include <stdio.h>
#include <string.h>
#include "matrix.h"
 
int main(int argc, char **argv) {
    FILE* textFile = fopen(argv[1], "r");
    Matrix mat;
    fscanf(textFile, "%d", &mat.row);
    fscanf(textFile, "%d", &mat.col);
	mat.arr = make_empty_matrix(mat.row, mat.col);
	for (int i=0; i<mat.row; ++i) {
	    for (int j=0; j<mat.col; ++j) {
	      fscanf(textFile, "%lf", &mat.arr[i][j]);
	    }
	}
    printf("The determinant is %.2lf.\n",  findDeterminant(mat));
}
