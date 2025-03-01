#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    int rows = matrixSize;
    int cols = *matrixColSize;

    // 使用 flag_row行和flag_col列进行记录
    int find = 0;
    int flag_row = 0;
    int flag_col = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                if (!find) {
                    // 一定是第一个0
                    flag_row = i;
                    flag_col = j;
                    find = 1;
                    printf("flag_row:%d flag_col:%d\n", flag_row, flag_col);
                } else {
                    matrix[flag_row][j] = 0; 
                    matrix[i][flag_col] = 0;
                }
            }
        }
    }

    if (!find) {
        return;
    }

    // 基于记录写入其他行和列
    for (int i = 0; i < rows; i++) {
        if (i != flag_row && matrix[i][flag_col] == 0) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < cols; j++) {
        if (j != flag_col && matrix[flag_row][j] == 0) {
            for (int i = 0; i < rows; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // 将用于记录的行与列，置0
    for (int i = 0; i < rows; i++) {
        matrix[i][flag_col] = 0;
    }
    for (int j = 0; j < cols; j++) {
        matrix[flag_row][j] = 0;
    }

    return;
}

int **build(int (*intervals)[4], int size) {
    int **res = calloc(size, sizeof(int *));
    // printf("res: %p\n", res);
    for (int i = 0; i < size; i++) {
        res[i] = calloc(4, sizeof(int));
        // printf("res[%d] : %p : %p\n", i, &res[i], res[i]);
        res[i][0] = intervals[i][0];
        res[i][1] = intervals[i][1];
        res[i][2] = intervals[i][2];
        res[i][3] = intervals[i][3];
        // printf("&res[i][0]: %p &res[i][1]:%p\n", &res[i][0], &res[i][1]);
    }
    return res;
}

int main()
{
    int mat[][4] = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5},
    };

    int **m = build(mat, 3);
    int col_size = 4;
    setZeroes(m, 3, &col_size);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < col_size; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}