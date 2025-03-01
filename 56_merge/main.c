/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmp(const void *interval1, const void *interval2)
{
    // printf("cmp: \n");
    int **arr1 = interval1;
    int **arr2 = interval2;
    // printf("%p:%lx %p:%lx\n", interval1, arr1[0][0], interval2, arr2[0][0]);
    return arr1[0][0] - arr2[0][0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    // 准备结果内存
    int **res = calloc(intervalsSize, sizeof(int *));
    for (int i = 0; i < intervalsSize; i++) {
        res[i] = calloc(2, sizeof(int));
    }
    int *ret_col_size = calloc(intervalsSize, sizeof(int));
    (*returnColumnSizes) = ret_col_size;

    qsort(intervals, intervalsSize , sizeof(int *), cmp);
    // for (int i = 0; i<intervalsSize; i++)
    //     printf("%d %d\n", intervals[i][0], intervals[i][1]);

    int count = 0;
    int start = 0;
    int end = 1;
    for (int i = 1; i < intervalsSize; i++) {
        // printf("i(%d): %d %d\n", i, intervals[start][1], intervals[i][0]);
        if (intervals[start][1] >= intervals[i][0]) {
            intervals[start][1] = MAX(intervals[start][1], intervals[i][1]);
            end++;
        } else {
            //  将 [start, end-1] 区间合并
            res[count][0] = intervals[start][0];
            res[count][1] = intervals[start][1];
            count++;
            // 下一步
            start = end;
            end = start +1;
        }
    }
    if (start < intervalsSize && end >= intervalsSize) {
        res[count][0] = intervals[start][0];
        res[count][1] = intervals[start][1];
        count++;
    }

    *returnSize = count;
    for (int i = 0; i < count; i++) {
        ret_col_size[i] = 2;
    }

    return res;
}

#include "../common.h"

int **build(int (*intervals)[2], int size) {
    int **res = calloc(size, sizeof(int *));
    printf("res: %p\n", res);
    for (int i = 0; i < size; i++) {
        res[i] = calloc(2, sizeof(int));
        printf("res[%d] : %p : %p\n", i, &res[i], res[i]);
        res[i][0] = intervals[i][0];
        res[i][1] = intervals[i][1];
        printf("&res[i][0]: %p &res[i][1]:%p\n", &res[i][0], &res[i][1]);
    }
    return res;
}
int main()
{
    int **res = NULL;
    int res_size = 0;
    int *res_col_size = NULL;

    // 示例 1：
    // 输入：intervals = {{1,3},{2,6},{8,10},{15,18}}
    // 输出：{{1,6},{8,10},{15,18}}
    // 解释：区间 {1,3} 和 {2,6} 重叠, 将它们合并为 {1,6}.
    int intervals1[][2] = {
        {1,10},
        {15,18},
        {2,9},
        {8,11},
    };
    int i1size = ARRAY_SIZE(intervals1);
    int **i1 = build(intervals1, i1size);
    int ic = 2;
    res = merge(i1, i1size, &ic, &res_size, &res_col_size);
    for (int i = 0; i < res_size; i++) {
        printf("[%d %d] ", res[i][0], res[i][1]);
    }

    return 0;
}

