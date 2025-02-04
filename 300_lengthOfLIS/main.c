#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

void debug_info(int *n, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
}

/*
 * dp[i] = max(dp[j])+1，其中0≤j<i且num[j]<num[i]
 */
int lengthOfLIS(int *nums, int numsSize) 
{
    int dp[2501] = {0};
    int maxdp = 1;

    for (int i = 0; i < numsSize; i++) {
        int dpi = 1;
        for (int j = 0; j < i; j++) {
            int dpj = dp[j] + 1;
            if (nums[i] > nums[j] && dpi < dpj) {
                dpi = dp[j] + 1;
            }
        }
        dp[i] = dpi;
        maxdp = (maxdp > dpi ? maxdp : dpi);
    }

    // debug_info(dp, numsSize);
    return maxdp;
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
int main()
{
    // 给你一个整数数组 nums，找到其中最长严格递增子序列的长度。
    // 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
    // 1 <= nums.length <= 2500
    // -104 <= nums[i] <= 104

    int ret = 0;
    // 示例 1：
    // 输入：nums = [10,9,2,5,3,7,101,18]
    // 输出：4
    // 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
    printf("\ntest\n");
    int n1[] = {10,9,2,5,3,7,101,18};
    ret = lengthOfLIS(n1, ARRAY_SIZE(n1));
    printf("ret: %d\n", ret);


    // 示例 2：
    // 输入：nums = [0,1,0,3,2,3]
    // 输出：4
    printf("\ntest\n");
    int n2[] = {0,1,0,3,2,3};
    ret = lengthOfLIS(n2, ARRAY_SIZE(n2));
    printf("ret: %d\n", ret);

    // 示例 3：
    // 输入：nums = [7,7,7,7,7,7,7]
    // 输出：1
    printf("\ntest\n");
    int n3[] = {7,7,7,7,7,7,7};
    ret = lengthOfLIS(n3, ARRAY_SIZE(n3));
    printf("ret: %d\n", ret);

    // 示例 4：
    // 输入：nums =  [1,3,6,7,9,4,10,5,6]
    // 输出：6
    printf("\ntest\n");
    int n4[] = {1,3,6,7,9,4,10,5,6};
    ret = lengthOfLIS(n4, ARRAY_SIZE(n4));
    printf("ret: %d\n", ret);
}