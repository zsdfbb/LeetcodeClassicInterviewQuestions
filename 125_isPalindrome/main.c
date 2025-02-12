#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char* s)
{
    int sl = strlen(s);

    // 大小写
    for (int i = 0; i < sl; i++) {
        s[i] = tolower(s[i]);
    }

    // 移出非数字、字母
    char ns[sl + 1];
    int ni = 0;
    for (int i = 0; i < sl; i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            ns[ni] = c;
            ni += 1;
        }
    }
    ns[ni] = '\0';

    // printf("ns: %s ni:%d\n", ns, ni);

    // 回文?
    bool ok = true;
    for (int i = 0; i < (ni >> 1); i++) {
        char c1 = ns[i];
        char c2 = ns[ni - i - 1];
        if (c1 != c2) {
            ok = false;
            break;
        }
    }

    return ok;
}

int main()
{
    // 示例 1：
    // 输入: s = "A man, a plan, a canal: Panama"
    // 输出：true
    // 解释："amanaplanacanalpanama" 是回文串。
    char s1[] = "A man, a plan, a canal: Panama";
    printf("%d\n", (int)isPalindrome(s1));

    // 示例 2：
    // 输入：s = "race a car"
    // 输出：false
    // 解释："raceacar" 不是回文串。
    char s2[] = "race a car";
    printf("%d\n", (int)isPalindrome(s2));

    // 示例 3：
    // 输入：s = " "
    // 输出：true
    // 解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
    // 由于空字符串正着反着读都一样，所以是回文串。
    char s3[] = " ";
    printf("%d\n", (int)isPalindrome(s3));

    // 示例 4：
    // 输入：s = "a"
    // 输出：true
    char s4[] = "a";
    printf("%d\n", (int)isPalindrome(s4));

    return 0;
}