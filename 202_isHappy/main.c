#include <stdio.h>
#include <stdbool.h>

int happy_next(int n)
{
    int res = 0;
    int v = 0;
    while (n) {
        v = n % 10;

        res += (v * v);
        n = n / 10;
    }

    return res;
}

bool isHappy(int n)
{
    int slow = n;
    int fast = n;
    while(true) {
        slow = happy_next(slow);
        if (slow == 1) {
            return true;
        }

        fast = happy_next(fast);
        fast = happy_next(fast);
        if (fast == 1) {
            return true;
        }

        //printf("%d %d\n", slow, fast);
        if (slow == fast) {
            return false;
        }
    }
}

/*
[快乐数] 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
*/
int main()
{
    // 示例 1：
    // 输入：n = 19
    // 输出：true
    // 解释：
    // 12 + 92 = 82
    // 82 + 22 = 68
    // 62 + 82 = 100
    // 12 + 02 + 02 = 1
    printf("%d\n", isHappy(19));

    // 示例 2：
    // 输入：n = 2
    // 输出：false
    printf("%d\n", isHappy(2));

    return 0;
}