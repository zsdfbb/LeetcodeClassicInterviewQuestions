#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int *res = 0;
    int *arr = calloc(digitsSize + 10, sizeof(int));
    int carry = 1;
    int i = 0;
    for (i = digitsSize; i > 0; i--) {
        int sum = digits[i - 1];
        if (carry) {
            sum++;
            carry = (sum > 9 ? 1 : 0);
        }
        arr[i] = sum % 10;
    }

    res = &arr[1];
    *returnSize = digitsSize;
    if (i == 0 && carry == 1) {
        arr[i] = 1;
        *returnSize = digitsSize + 1;
        res = &arr[0];
    }

    return res;
}

void debug_info(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
int main()
{
    // 示例 1：
    // 输入：digits = [1,2,3]
    // 输出：[1,2,4]
    // 解释：输入数组表示数字 123。
    int d1[] = {1,2,3};
    int retsize = 0;
    int *ret = plusOne(d1, ARRAY_SIZE(d1), &retsize);
    printf("%d\n", retsize);
    debug_info(ret, retsize);


    // 示例 2：
    // 输入：digits = [4,3,2,1]
    // 输出：[4,3,2,2]
    // 解释：输入数组表示数字 4321。
    int d2[] = {4,3,2,1};
    ret = plusOne(d2, ARRAY_SIZE(d2), &retsize);
    printf("%d\n", retsize);
    debug_info(ret, retsize);

    // 示例 3：
    // 输入：digits = [9]
    // 输出：[1,0]
    // 解释：输入数组表示数字 9。
    // 加 1 得到了 9 + 1 = 10。
    // 因此，结果应该是 [1,0]。
    int d3[] = {9};
    ret = plusOne(d3, ARRAY_SIZE(d3), &retsize);
    printf("%d\n", retsize);
    debug_info(ret, retsize);
}