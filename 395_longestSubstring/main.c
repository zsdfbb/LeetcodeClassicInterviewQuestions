#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 分治方法
int longestSubstring(char* s, int k)
{
    int count[26] = {0};
    int sl = strlen(s);
    for (int i = 0; i < sl; i++) {
        count[s[i] - 'a'] ++;
    }

    int split = 0;
    for (int i = 0; i < sl ;i++) {
        int cn = s[i] - 'a';
        if (count[cn] < k) {
            s[i] = '\0';
            // 发生了split，证明s需要分裂
            split = 1;
        }
    }
    if (!split) {
        // 如果不需要分裂，证明它是合法的
        return sl;
    }

    int start = 0;
    int res = 0;
    for (int i = 0; i < sl; i++) {
        if ((i > 0 && s[i-1] == '\0' && s[i] != '\0') || (i == 0 && s[i] != '\0')) {
            // 是一个sub string的起点
            int ret = longestSubstring(s+i, k);
            res = (ret > res ? ret : res);
        }
    }

    return res;
}

int main()
{
    // 示例 1：
    // 输入：s = "aaabb", k = 3
    // 输出：3
    // 解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
    char s1[] = "aaabb";
    printf("%d\n", longestSubstring(s1, 3));

    // 示例 2：
    // 输入：s = "ababbc", k = 2
    // 输出：5
    // 解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
    char s2[] = "ababbc";
    printf("%d\n", longestSubstring(s2, 2));

    return 0;
}