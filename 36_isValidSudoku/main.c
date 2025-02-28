#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    // count[i][num] 是数字num在第i行出现的次数，次数最大不应该超过1
    int count_line[10][10] = {0};
    // count[num][j] 是数字num在第j列出现的次数，次数最大不应该超过1
    int count_col[10][10] = {0};
    // count[mat][num] 是数字num在第mat个矩阵中出现的次数，次数最大不应该超过1
    int count_mat[10][10] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                continue;
            }

            int num = board[i][j] - '0';

            if (count_line[i][num] == 1) {
                return false;
            }
            count_line[i][num]++;

            if (count_col[num][j] == 1) {
                return false;
            }
            count_col[num][j]++;

            int mat = (i/3)*3 + j/3;
            if (count_mat[mat][num] ==1) {
                return false;
            }
            count_mat[mat][num]++;
        }
    }
    return true;
}
