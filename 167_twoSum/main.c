#include "stdio.h"
#include "stdlib.h"
#include "../common.h"

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int *res = NULL;
    int index1 = -1;
    int index2 = -1;
    *returnSize = 0;

    for (int i = 0; i < numbersSize; i++) {
        int v1 = numbers[i];
        int v2 = target - v1;
        if (v1 > v2) {
            break;
        }

        // v2 存在 numbers[i+1 .. numberSize] ？
        for (int j = i + 1; j < numbersSize; j++) {
            if (numbers[j] == v2) {
                index1 = i;
                index2 = j;
            }
        }
    }

    // 如果有答案，保存答案
    if (index1 != -1) {
        res = malloc(2 * sizeof(int));
        res[0] = index1 + 1;
        res[1] = index2 + 1;

        *returnSize = 2;
    }

    return res;
}


int qsearch(int *numbers, int start, int end, int target)
{
    int index = -1;

    int left = start;
    int right = end;
    // 0 1 2 3
    int mid = 0;
    int mv = 0;
    while (left <= right) {
        mid = (left + (right - left) / 2);
        mv = numbers[mid];
        
        if (mv == target) {
            index = mid;
            break;
        } 

        // printf("left:%d mid:%d right:%d numbers[mid]: %d\n", left, mid, right, mv);
        if (mv < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        // printf("left:%d mid:%d right:%d numbers[mid]: %d\n", left, mid, right, mv);
    }

    return index;
}

int* twoSum1(int* numbers, int numbersSize, int target, int* returnSize)
{
    int *res = NULL;
    int index1 = -1;
    int index2 = -1;
    *returnSize = 0;

    for (int i = 0; i < numbersSize; i++) {
        int v1 = numbers[i];
        int v2 = target - v1;
        if (v1 > v2) {
            break;
        }

        // v2 存在 numbers[i+1 .. numberSize] ？
        // 二分查找
        index2 = qsearch(numbers, i+1, numbersSize - 1, v2);
        if (index2 != -1) {
            index1 = i;
            break;
        }
    }

    // 如果有答案，保存答案
    if (index1 != -1) {
        res = malloc(2 * sizeof(int));
        res[0] = index1 + 1;
        res[1] = index2 + 1;

        *returnSize = 2;
    }

    return res;

}

int main()
{
    int *res = NULL;
    int size = 0;
    // 示例 1：
    // 输入：numbers = [2,7,11,15], target = 9
    // 输出：[1,2]
    // 解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
    int n1[] = {2,7,11,15};
    int t1 = 9;
    // res = twoSum(n1, ARRAY_SIZE(n1), t1, &size);
    res = twoSum1(n1, ARRAY_SIZE(n1), t1, &size);
    debug_info(res, size);
    free(res);

    // 示例 2：    
    // 输入：numbers = [2,3,4], target = 6
    // 输出：[1,3]
    // 解释：2 与 4 之和等于目标数 6 。因此 index1 = 1, index2 = 3 。返回 [1, 3] 。
    int n2[] = {2,3,4};
    int t2 = 6;
    // res = twoSum(n2, ARRAY_SIZE(n2), t2, &size);
    res = twoSum1(n2, ARRAY_SIZE(n2), t2, &size);
    debug_info(res, size);
    free(res);

    // 示例 3：
    // 输入：numbers = [-1,0], target = -1
    // 输出：[1,2]
    // 解释：-1 与 0 之和等于目标数 -1 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
    int n3[] = {-1,0};
    int t3 = -1;
    // res = twoSum(n3, ARRAY_SIZE(n3), t3, &size);
    res = twoSum1(n3, ARRAY_SIZE(n3), t3, &size);
    debug_info(res, size);
    free(res);

    return 0;
}