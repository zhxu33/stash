#include <stdio.h>

int main() {
    int row;
    int col;
    printf("Please enter the number of rows: ");
    scanf("%d", &row);
    printf("Please enter the number of columns: ");
    scanf("%d", &col);
    int matrixA[row][col];  
    int matrixB[row][col];  
    printf("Enter Matrix A\n");
    for (int i = 0; i < row; ++i) {
        char newline = ' ';
        int k=0;
        while (k < col) {
            scanf("%d%c", &matrixA[i][k], &newline);
            k++;
        }
    }
    printf("Enter Matrix B\n");
    for (int i = 0; i < row; ++i) {
        char newline = ' ';
        int k=0;
        while (k < col) {
            scanf("%d%c", &matrixB[i][k], &newline);
            k++;
        }
    }
    printf("A + B =\n");
    for (int i = 0; i < row; ++i) {
       for (int k = 0; k < col; ++k) { 
        int added = matrixA[i][k]+matrixB[i][k];
        printf("%d ", added);
       }
       printf("\n");
    }
}