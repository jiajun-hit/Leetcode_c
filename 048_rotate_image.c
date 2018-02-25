#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int temp;

    for (int i = 0; i < matrixRowSize; i++) {
        for (int j = 0; j < i; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (int i = 0; i < matrixRowSize; i++) {
        for (int j = 0; j < matrixRowSize/2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixRowSize-1 -j];
            matrix[i][matrixRowSize-1 -j] = temp;
        }
    }
}

int main() {
    int aaa[4][4] = {{5, 1, 9, 11},
                        {2, 4, 8, 10},
                        {13, 3, 6, 7},
                        {15, 14, 12, 16}};
    int row = 4;
    int col = 4;

    int** aa = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        aa[i] = (int *)malloc(col * sizeof(int));
    }

    for (int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            aa[i][j] = aaa[i][j];
        }
    }

    rotate(aa, row, &col);

    for (int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%2d ", aa[i][j]);
        }
        printf("\n");
    }

    return 0;
}
