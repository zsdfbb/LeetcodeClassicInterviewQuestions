#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int strStr(char* haystack, char* needle)
{
    int hl = strlen(haystack);
    int nl = strlen(needle);

    for (int i = 0; i < hl - nl + 1; i++) {
        int start = i;
        bool ok = true;
        for (int j = 0; j < nl; j++) {
            if (needle[j] != haystack[start + j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return start;
        }
    }
    return -1;
}

int main()
{
    int ret = 0;
    // 示例 1：
    // 输入：haystack = "sadbutsad", needle = "sad"
    // 输出：0
    // 解释："sad" 在下标 0 和 6 处匹配。
    // 第一个匹配项的下标是 0 ，所以返回 0 。
    char h1[] = "sadbutsad";
    char n1[] = "sad";
    ret = strStr(h1, n1);
    printf("%d\n", ret);


    // 示例 2：
    // 输入：haystack = "leetcode", needle = "leeto"
    // 输出：-1
    // 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
    char h2[] = "leetcode";
    char n2[] = "leeto";
    ret = strStr(h2, n2);
    printf("%d\n", ret);
    return 0;
}