#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int x)
{
    int a[64] = {0};
    int r = -1;
    int l = 0;

    if (x < 0) {
        return false;
    }

    if (x == 0) {
        return true;
    }

    while (x > 0) {
        a[++r] = x % 10;
        x = x / 10;
    }

    while (l < r) {
        printf("%d %d\n", a[l], a[r]);
        if (a[l] != a[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main()
{

    // 示例 1：
    // 输入：x = 121
    // 输出：true
    int x1 = 121;
    printf("res: %d\n", (int)isPalindrome(x1));

    // 示例 2：
    // 输入：x = -121
    // 输出：false
    // 解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
    int x2 = -121;
    printf("res: %d\n", (int)isPalindrome(x2));

    // 示例 3：
    // 输入：x = 10
    // 输出：false
    // 解释：从右向左读, 为 01 。因此它不是一个回文数。
    int x3 = 10;
    printf("res: %d\n", (int)isPalindrome(x3));
}