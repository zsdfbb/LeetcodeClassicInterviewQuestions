#include <stdio.h>
#include <stdlib.h>

#include "../common.h"

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *res = calloc(2, sizeof(int));
    *returnSize = 2;

    // 对nums进行排序
    int *nl = calloc(numsSize, sizeof(int) * 2);
    for (int i = 1; i <= numsSize; i++) {
        nl[(i << 1) -2] = nums[i - 1];
        nl[(i << 1) -1] = i - 1;
    }

    qsort(nl, numsSize, sizeof(int) * 2, cmp);
    debug_info(nl, numsSize * 2);


    // 开始迭代，先选一个数字 n，然后查找 target -n， 如果存在，则找到并记录
    for (int i = 1; i <= numsSize; i++) {
        int n = nl[(i<<1) - 2];
        int fn = target - n;

        if (fn < n) {
            break;
        }

        printf("n: %d, fn: %d\n", n, fn);
        int *fs = bsearch(&fn, &nl[i << 1], numsSize - i, sizeof(int) << 1, cmp);
        if (fs != NULL) {
            // find it!
            res[0] = nl[(i<<1) - 1];
            res[1] = *(fs+1);
            break;
        }
    }

    free(nl);
    return res;
}

int main()
{

    int *res = NULL;
    int res_size = 0;

    // 示例 1：输入：nums = [2,7,11,15], target = 9
    // 输出：[0,1]
    // 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
    int n1[] = {2,7,11,15};
    res = twoSum(n1, ARRAY_SIZE(n1), 9, &res_size);
    debug_info(res, res_size);
    free(res);

    // 示例 2：输入：nums = [3,2,4], target = 6
    // 输出：[1,2]
    int n2[] = {3,2,4};
    res = twoSum(n2, ARRAY_SIZE(n2), 6, &res_size);
    debug_info(res, res_size);
    free(res);


    // 示例 3：输入：nums = [3,3], target = 6
    // 输出：[0,1]
    int n3[] = {3,3};
    res = twoSum(n3, ARRAY_SIZE(n3), 6, &res_size);
    debug_info(res, res_size);
    free(res);

    return 0;
}
