#include <stdio.h>
#include <time.h>

// 动态规划问题

// 递归：
// 问题的解由子问题的解组成
// 第n个的结果, 由n-1和n-2两个子问题的解组成，我们只需要递归解决即可。
// 因为n-1 向上跳一步就是n，n-2向上跳两步就是n，没有其他的跳上来的可能性
// dp[n] = dp[n-1] + dp[n-2]
// Notice：s递归要慢很多
int climbStairs1(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int ret = climbStairs1(n - 1) + climbStairs1(n - 2);
    return ret;
}

// 使用数组记录结果，快很多
int climbStairs2(int n) {
    int dp[64] = {0};
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    int ret = dp[n];
    return ret;
}

void timeinfo(int n)
{
    clock_t start_t, finish_t;
    double total_t = 0;
    int ret = 0;

    start_t = clock();
    ret = climbStairs1(n);
    finish_t = clock();
    total_t = (double)(finish_t - start_t) / CLOCKS_PER_SEC;
    printf("%f\n", total_t);

    start_t = clock();
    ret = climbStairs2(n);
    finish_t = clock();
    total_t = (double)(finish_t - start_t) / CLOCKS_PER_SEC;
    printf("%f\n", total_t);
}

int main()
{
    for (int n = 1; n <= 45; n++) {
        printf("n(%d): %d %d\n", n, climbStairs1(n), climbStairs2(n));
        timeinfo(n);
    }
    return 0;
}
