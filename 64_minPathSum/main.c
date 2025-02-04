#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MAX_VAL 512
#define DP_SIZE 256

void debug_dp(void *dp, int m, int n)
{
    //printf("dp info:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = *((int *)dp + i * DP_SIZE + j);
            printf("%d ", val);
        }
        printf("\n");
    }
}


static inline bool is_valid(int m, int n, int i, int j)
{
    if (i >= 0 && i < m && j >= 0 && j < n) {
        return true;
    }
    return false;
}

static int grid_val(int** grid, int i, int j)
{
    return *(grid[i] + j);
}

int final_val(int left_num, int up_num) {
    if (left_num >= 0 && up_num >= 0) {
        return MIN(left_num, up_num);
    }
    return MAX(left_num, up_num);
}

int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize;
    int n = *gridColSize;
    //printf("m:%d n:%d\n", m, n);
    int dp[DP_SIZE][DP_SIZE] = {0};

    // 按照对角线开始推动dp计算，对角线数量
    int t = 1;
    int times = m + n - 1;
    dp[0][0] = grid_val(grid, 0, 0);
    while (t < times) {
        int i = 0;
        int j = 0;
        for (; i <= t; i++) {
            j = t - i;
            if (!is_valid(m, n, i , j)) {
                continue;
            }
            
            //printf("i: %d j:%d\n", i, j);
            
            int up_sum = -1;
            if (is_valid(m, n, i - 1, j)) {
                up_sum = dp[i - 1][j] + grid_val(grid, i, j);
            }

            int left_sum = -1;
            if (is_valid(m, n, i, j - 1)) {
                left_sum = dp[i][j - 1] + grid_val(grid, i, j);
            }
            //printf("leftn: %d upn: %d\n", left_sum, up_sum);
            dp[i][j] = final_val(left_sum, up_sum);
            // debug_dp((void *)dp, m, n);
        }
        t++;
    }
    return dp[m -1][n - 1];
}

int minPathSum_v1(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize;
    int n = *gridColSize;
    //printf("m:%d n:%d\n", m, n);
    int dp[DP_SIZE][DP_SIZE] = {0};

    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    //debug_dp((void *)dp, m, n);

    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    //debug_dp((void *)dp, m, n);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = MIN(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    //debug_dp((void *)dp, m, n);

    return dp[m -1][n - 1];
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main()
{
    int ret = 0;
    // 示例 1：
    // 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
    // 输出：7
    // 解释：因为路径 1→3→1→1→1 的总和最小。
    int **grid = (int **)malloc(sizeof(int *) * 3);
    grid[0] = (int *)malloc(sizeof(int) * 3);
    *(grid[0] + 0) = 1;
    *(grid[0] + 1) = 3;
    *(grid[0] + 2) = 1;

    grid[1] = (int *)malloc(sizeof(int) * 3);
    *(grid[1] + 0) = 1;
    *(grid[1] + 1) = 5;
    *(grid[1] + 2) = 1;

    grid[2] = (int *)malloc(sizeof(int) * 3);
    *(grid[2] + 0) = 4;
    *(grid[2] + 1) = 2;
    *(grid[2] + 2) = 1;
    //printf("debug main 1\n");

    int gridColSize = 3;
    ret = minPathSum((int **)grid, 3, &gridColSize);
    //printf("ret = %d\n", ret);
    ret = minPathSum_v1(grid, 3, &gridColSize);
    printf("ret = %d\n", ret);

    // 示例 2：
    // 输入：grid = [[1,2,3],[4,5,6]]
    // 输出：12
    int **grid1 = (int **)malloc(sizeof(int *) * 2);
    grid1[0] = (int *)malloc(sizeof(int) * 3);
    grid1[0][0] = 1;
    grid1[0][1] = 2;
    grid1[0][2] = 3;

    grid1[1] = (int *)malloc(sizeof(int) * 3);
    grid1[1][0] = 4;
    grid1[1][1] = 5;
    grid1[1][2] = 6;
    gridColSize = 3;
    ret = minPathSum(grid1, 2, &gridColSize);
    //printf("ret = %d\n", ret);
    ret = minPathSum_v1(grid1, 2, &gridColSize);
    printf("ret = %d\n", ret);

    // 示例 3：
    // 输入：
    // [[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100],[100,100,100]]
    // 输出：5400

    int **grid2 = (int **)malloc(sizeof(int *) * 52);
    for (int i = 0; i < 52; i++) {
        grid2[i] = (int *)malloc(sizeof(int) * 3);
        for (int j = 0; j < 3; j++) {
            grid2[i][j] = 100;
        }
    }
    gridColSize = 3;
    ret = minPathSum(grid2, 52, &gridColSize);
    //printf("%d\n", ret);
        ret = minPathSum_v1(grid2, 52, &gridColSize);
    printf("ret = %d\n", ret);


    return 0;
}