#include <stdio.h>

int main() {
    int levels;
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d", &levels);
    int prevArr[28];
    for (int i=1; i<=levels; ++i) {
        int arr[i];
        for (int k=0; k<i; ++k) {
            if (k == 0 || k == (i-1)) {
                arr[k] = 1; 
            } else {
                arr[k] = prevArr[k-1] + prevArr[k];
            }
            printf("%d ", arr[k]);
        }
        printf("\n");
        for (int k=0; k<i; ++k) {
            prevArr[k] = arr[k];
        }
    }
}

