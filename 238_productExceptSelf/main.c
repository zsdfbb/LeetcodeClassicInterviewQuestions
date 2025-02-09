#include "../common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int *a = (int *)calloc(numsSize, sizeof(int));
    // 左侧元素乘积
    int lm[numsSize];
    // 右侧元素乘积
    int rm[numsSize];

    lm[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        lm[i] = lm[i-1] * nums[i]; 
    }

    rm[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >=0; i--) {
        rm[i] = rm[i + 1] * nums[i];
    }

    // answer[i] = lm[i -1] * rm[i + 1];
    for (int i = 1; i < numsSize -1; i++) {
        a[i] = lm[i - 1] * rm[i + 1];
    }
    a[0] = rm[1];
    a[numsSize -1] = lm[numsSize -2];
    *returnSize = numsSize;

    return a;
}

int main()
{
    // 示例 1:
    // 输入: nums = [1,2,3,4]
    // 输出: [24,12,8,6]
    int n1[] = {1,2,3,4};
    int size = 0;
    int *res = productExceptSelf(n1, ARRAY_SIZE(n1), &size);
    debug_info(res, size);
    free(res);

    // 示例 2:
    // 输入: nums = [-1,1,0,-3,3]
    // 输出: [0,0,9,0,0]
    int n2[] = {-1,1,0,-3,3};
    size = 0;
    res = productExceptSelf(n2, ARRAY_SIZE(n2), &size);
    debug_info(res, size);
    free(res);

    return 0;
}