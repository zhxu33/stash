#ifndef MATRIX_H
#define MATRIX_H

    typedef struct Matrix_struct  {
       int row;
       int col;
       double **arr;
    } Matrix;
    double** make_empty_matrix(int row_dim, int col_dim);
    double findDeterminant(Matrix mat);

#endif
