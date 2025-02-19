#include "../common.h"
#include <stdio.h>

int hammingWeight(int n) {
    unsigned int num = n;
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (num & 1) {
            count++;
        }
        num = num >> 1;
    }

    return count;
}

int main()
{
    // 输入：n = 11
    // 输出：3
    // 解释：输入的二进制串 1011 中，共有 3 个设置位。
    printf("%d\n", hammingWeight(11));
}
