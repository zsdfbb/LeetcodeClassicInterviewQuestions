#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// 暴力 n^2
int maxProfit(int* prices, int pricesSize)
{
    int res = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            int t = prices[j] - prices[i];
            res = (res > t ? res : t);
        }
    }
    return res;
}


void debug_info(int *n, int size)
{
    for (int i = 0; i<size; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
}

// 最大差值只关心 cur_val 和 后续 max_val
// 我们逆序统计后续的max_val，然后在计算一次差值即可
int maxProfit1(int* prices, int pricesSize)
{
    int res = 0;
    int max_prices[pricesSize];
    max_prices[pricesSize -1] = prices[pricesSize -1];
    for (int i = pricesSize -2; i >=0; i--) {
        int cur_price = prices[i];
        max_prices[i] = (max_prices[i + 1] > cur_price ? max_prices[i + 1] : cur_price);
    }
    // debug_info(max_prices, pricesSize);

    for (int i = 0; i < pricesSize - 1; i++) {
        int tmp = max_prices[i + 1] - prices[i];
        res = (res > tmp ? res : tmp);
    }
    return res;
}

// 类似前面的做法，换一种角度
// 我们记录一下前面的最低点，然后和当前值比较，就会得出当前节点的最大收益
int maxProfit2(int* prices, int pricesSize)
{
    int min_val = prices[0];
    int res = 0;
    for (int i = 1; i < pricesSize; i++) {
        int tmp = prices[i] - min_val;
        res = (res > tmp ? res : tmp);

        min_val = (min_val < prices[i] ? min_val : prices[i]);
    }
    return res;
}


#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
int main()
{

    // 示例 1：
    // 输入：[7,1,5,3,6,4]
    // 输出：5
    // 解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
    //     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
    int p1[] = {7,1,5,3,6,4};
    // printf("%d\n", maxProfit(p1, ARRAY_SIZE(p1)));
    // printf("%d\n", maxProfit1(p1, ARRAY_SIZE(p1)));
    printf("%d\n", maxProfit2(p1, ARRAY_SIZE(p1)));

    // 示例 2：
    // 输入：prices = [7,6,4,3,1]
    // 输出：0
    // 解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
    int p2[] = {7,6,4,3,1};
    // printf("%d\n", maxProfit(p2, ARRAY_SIZE(p2)));
    // printf("%d\n", maxProfit1(p2, ARRAY_SIZE(p2)));
    printf("%d\n", maxProfit2(p2, ARRAY_SIZE(p2)));
}