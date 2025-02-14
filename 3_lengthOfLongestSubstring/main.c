#include "string.h"
#include "../common.h"
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int sl = strlen(s);
    if (sl == 0) {
        return 0;
    }

    int left = 0;
    int right = 0;
    int max = 1;
    while (left < sl && right < sl) {
        //printf("left: %d, right: %d\n", left, right);
        char rc = s[right];
        for (int i = right - 1; i >= left; i--) {
            if (s[i] == rc) {
                left = i + 1;
                break;
            }
        }

        int tmp = (right - left + 1);
        max = (max > tmp ? max : tmp);
        right += 1;
    }
    return max;
}

int main()
{
    // 示例 1:
    // 输入: s = "abcabcbb"
    // 输出: 3 
    // 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
    char s1[] = "abcabcbb";
    printf("%d\n", lengthOfLongestSubstring(s1));

    // 示例 2:
    // 输入: s = "bbbbb"
    // 输出: 1
    // 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
    char s2[] = "bbbbb";
    printf("%d\n", lengthOfLongestSubstring(s2));

    // 示例 3:
    // 输入: s = "pwwkew"
    // 输出: 3
    // 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
    //     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
    char s3[] = "pwwkew";
    printf("%d\n", lengthOfLongestSubstring(s3));

    return 0;
}