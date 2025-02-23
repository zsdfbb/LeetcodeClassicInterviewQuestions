#include "stdbool.h"
#include "stdio.h"
#include <stdio.h>

bool isAnagram(char* s, char* t)
{
    int sum = 0;
    int cmap[512] = {0};
    while (*s != '\0') {
        cmap[*s]++;
        sum++;

        s++;
    }

    while (*t != '\0') {
        cmap[*t]--;
        // 每种字符数量必须一致
        if (cmap[*t] < 0) {
            return false;
        }
        sum--;

        t++;
    }

    // 整体数量必须一致
    return sum == 0;
}

int main()
{
    // 示例 1:
    // 输入: s = "anagram", t = "nagaram"
    // 输出: true
    printf("%d\n", isAnagram("anagram", "nagaram"));

    // 示例 2:
    // 输入: s = "rat", t = "car"
    // 输出: false
    printf("%d\n", isAnagram("rat", "car"));

    return 0;
}