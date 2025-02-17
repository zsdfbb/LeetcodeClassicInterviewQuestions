#include <string.h>

#include "../common.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int rob(int* nums, int numsSize)
{
    if (numsSize == 1) {
        return nums[0];
    }

    int dp[numsSize + 1];
    memset(dp, 0, numsSize + 1);
    dp[0] = nums[0];
    dp[1] = MAX(nums[0], nums[1]);

    for (int i = 2; i < numsSize; i++) {
        dp[i] = MAX(dp[i-1], dp[i-2] + nums[i]);
    }

    // debug_info(dp, numsSize);
    return dp[numsSize-1];
}

int main()
{
    // 示例 1：
    // 输入：[1,2,3,1]
    // 输出：4
    // 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
    //     偷窃到的最高金额 = 1 + 3 = 4 。
    int m1[] = {1,2,3,1};
    printf("res: %d\n", rob(m1, ARRAY_SIZE(m1)));

    // 示例 2：
    // 输入：[2,7,9,3,1]
    // 输出：12
    // 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
    //     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
    int m2[] = {2,7,9,3,1};
    printf("res: %d\n", rob(m2, ARRAY_SIZE(m2)));

    // 2,1,1,2
    // 输出：4
    int m3[] = {2,1,1,2};
    printf("res: %d\n", rob(m3, ARRAY_SIZE(m3)));


    return 0;
}