#include "string.h"
#include "stdbool.h"
#include "../common.h"

int str_match(char *s, char *head)
{
    char *old = head;
    if (s == NULL || head == NULL) {
        return 0;
    }

    // printf("s: %s head:%s\n", s, head);
    int i = 0;
    while (*s != '\0') {
        if (*head == '\0') {
            break;
        }

        if (*s == *head) {
            s++;
            head++;
        } else {
            return 0;
        }
    }
    if(*head == '\0') {
        return head - old;
    }

    return 0;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize)
{
    int sl = strlen(s);

    // dp[i] = 1, 表示 s[0..i-1] 可以被wordDict的单词表示
    // dp[i] = 0, 表示 s[0..i-1] 不可以被wordDict的单词表示
    int dp[sl + 1];
    for (int i = 0; i < sl; i++) {
        dp[i] = 0;
    }

    // debug_info(dp, sl + 1);
    for (int i = 0; i < sl; i++) {
        // printf("i: %d\n", i);
        if (i != 0 && dp[i - 1] == 0) {
            // 不能从当前节点开始进行匹配
            // printf("Do not match\n");
            continue;
        }
        // 从 s[i] 开始匹配
        for (int j = 0; j < wordDictSize; j++) {
            int ml = str_match(&s[i], wordDict[j]);
            if (ml && (i + ml -1) < sl + 1) {
                dp[i + ml-1] = 1;
            }
        }
        // debug_info(dp, sl + 1);
    }

    // debug_info(dp, sl + 1);
    return dp[sl-1] == 1;
}

int main()
{
    // 示例 1：
    // 输入: s = "leetcode", wordDict = ["leet", "code"]
    // 输出: true
    // 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
    char s1[] = "leetcode";
    char *wd1[] = {"leet", "code"};
    printf("res: %d\n", (int)wordBreak(s1, wd1, ARRAY_SIZE(wd1)));

    // 示例 2：
    // 输入: s = "applepenapple", wordDict = ["apple", "pen"]
    // 输出: true
    // 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
    //     注意，你可以重复使用字典中的单词。
    char s2[] = "applepenapple";
    char *wd2[] = {"apple", "pen"};
    printf("res: %d\n", (int)wordBreak(s2,  wd2, ARRAY_SIZE(wd2)));

    // 示例 3：
    // 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
    // 输出: false
    char s3[] = "catsandog";
    char *wd3[] = {"cats", "dog", "sand", "and", "cat"};
    printf("res: %d\n", (int)wordBreak(s3,  wd3, ARRAY_SIZE(wd3)));

    return 0;
}