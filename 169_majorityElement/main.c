#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// Boyer-Moore 投票算法
int majorityElement(int* nums, int numsSize)
{
    int count = 0;
    int candidate = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        if (candidate == nums[i]) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
int main()
{
    int ret = 0;
    // 示例 1：
    // 输入：nums = [3,2,3]
    // 输出：3
    int n1[] = {3,2,3};
    ret = majorityElement(n1, ARRAY_SIZE(n1));
    printf("%d\n", ret);

    // 示例 2：
    // 输入：nums = [2,2,1,1,1,2,2]
    // 输出：2
    int n2[] = {2,2,1,1,1,2,2};
    ret = majorityElement(n2, ARRAY_SIZE(n2));
    printf("%d\n", ret);

    int n3[] = {3,3,4};
    ret = majorityElement(n3, ARRAY_SIZE(n3));
    printf("%d\n", ret);

    return 0;
}
