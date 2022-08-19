#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

double** make_empty_matrix(int row_dim, int col_dim) {
	double **matrix = (double**)malloc(sizeof(double)*row_dim);
	for (int i=0; i<row_dim; ++i) {
	    matrix[i] = (double*)malloc(sizeof(double)*(col_dim));
	}
	return matrix;
}

double findDeterminant(Matrix mat) {
    double determinant = 0;
    if (mat.row == 1) {
        return mat.arr[0][0];
    } else if (mat.row > 1) {
        for (int i=0; i<mat.row; ++i) {
            Matrix newMat;
            newMat.row = mat.row-1;
            newMat.col = mat.col-1;
            newMat.arr = make_empty_matrix(newMat.row,newMat.col);
            int l=0;
            int m=0;
            for(int j=0; j<mat.row; j++) {
                for (int k=0; k<mat.row; k++) {
                    if (j!=0&&k!=i) {
                        newMat.arr[l][m] = mat.arr[j][k];
                        if (m==mat.row-2) {
                            m=0;
                            l++;
                        }  else {
                            m++;
                        }
                    }
                }
            }
            double val = mat.arr[0][i];
            if (i%2==0) {
                determinant = determinant+val*findDeterminant(newMat);
            } else {
                determinant = determinant-val*findDeterminant(newMat);
            }
        }
    } 
    return determinant;
}