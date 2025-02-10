#include "../common.h"

int lengthOfLastWord(char* s)
{
    int sl = strlen(s);

    int end;
    for (end = sl - 1; end >= 0; end--) {
        if (s[end] != ' ') {
            break;
        }
    }

    int start;
    for (start = end; start >= 0; start--) {
        if (s[start] == ' ') {
            break;
        }
    }

    return end - start;
}

int main()
{
    // 示例 1：
    // 输入：s = "Hello World"
    // 输出：5
    // 解释：最后一个单词是“World”，长度为 5。
    char s1[] = "Hello World";
    printf("ret: %d\n", lengthOfLastWord(s1));

    // 示例 2：
    // 输入：s = "   fly me   to   the moon  "
    // 输出：4
    // 解释：最后一个单词是“moon”，长度为 4。
    char s2[] = "moon";
    printf("ret: %d\n", lengthOfLastWord(s2));

    // 示例 3：
    // 输入：s = "luffy is still joyboy"
    // 输出：6
    // 解释：最后一个单词是长度为 6 的“joyboy”。
    char s3[] = "luffy is still joyboy";
    printf("ret: %d\n", lengthOfLastWord(s3));

    return 0;
}