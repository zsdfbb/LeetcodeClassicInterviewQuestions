#include <string.h>

#include "../common.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
int coinChange(int* coins, int coinsSize, int amount)
{
    if (amount == 0) {
        return 0;
    }

    // 初始化dp
    int dp[amount + 1];
    for (int i = 0; i < amount + 1; i++) {
        dp[i] = amount +1;
    }
    for (int i = 0; i < coinsSize; i++) {
        int c = coins[i];
        if (c < amount +1) {
            dp[c] = 1;
        }
    }
    // debug_info(dp, amount + 1);

    // 迭代dp
    for (int l = 1; l < amount + 1; l++) {
        for (int i = 0; i < coinsSize; i++) {
            // dp[l] = MIN(dp[l - coins_i], ... ,dp[l - coins_j]) + 1
            int pre = l - coins[i];
            if (pre > 0 && dp[pre] < amount) {
                dp[l] = MIN(dp[l], dp[pre] + 1);
            }
        }
    }

    // debug_info(dp, amount + 1);

    if (dp[amount] > amount) {
        return -1;
    }
    return dp[amount];
}

int main()
{
    // 示例 1：
    // 输入：coins = [1, 2, 5], amount = 11
    // 输出：3 
    // 解释：11 = 5 + 5 + 1
    int c1[] = {1, 2, 5};
    printf("res: %d\n", coinChange(c1, ARRAY_SIZE(c1), 11));

    // 示例 2：
    // 输入：coins = [2], amount = 3
    // 输出：-1
    int c2[] = {2};
    printf("res: %d\n", coinChange(c2, ARRAY_SIZE(c2), 3));

    // 示例 3：
    // 输入：coins = [1], amount = 0
    // 输出：0
    int c3[] = {1};
    printf("res: %d\n", coinChange(c3, ARRAY_SIZE(c3), 0));

    return 0;
}