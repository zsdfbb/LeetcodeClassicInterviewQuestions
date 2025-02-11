#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* reverseWords(char* s)
{
    int sl = strlen(s);
    char *res = malloc(sizeof(char) * (sl + 1));
    int ri = 0;
    // printf("sl: %d\n", sl);
    int ws = sl -1;
    int we = sl -1;
    while (we >= 0) {
        // ws: word start 
        // we: word end
        while (we >= 0 && s[we] == ' ') {
            we--;
        }
        if (we < 0) {
            break;
        }
        ws = we;
        while (ws >= 0 && s[ws] != ' ') {
            ws--;
        }
        // printf("ws: %d we: %d\n", ws, we);
        // copy word
        // printf("start ri: %d\n", ri);
        for (int i = 0; i < (we - ws); i++) {
            res[ri] = s[ws + 1 + i];
            ri++;
        }
        // append space
        res[ri] = ' ';
        ri++;
        // printf("end ri: %d\n", ri);
        we = ws;
    }
    res[ri -1] = '\0';
    return res;
}
int main()
{
    // 示例 1：
    // 输入：s = "the sky is blue"
    // 输出："blue is sky the"
    printf("示例 1\n");
    char c1[] = "the sky is blue";
    char *res = reverseWords(c1);
    printf("res: %s\n", res);
    free(res);
    // 示例 2：
    // 输入：s = "  hello world  "
    // 输出："world hello"
    // 解释：反转后的字符串中不能存在前导空格和尾随空格。
    printf("示例 2\n");
    char c2[] = "  hello world  ";
    res = reverseWords(c2);
    printf("res: %s\n", res);
    free(res);
    // 示例 3：
    // 输入：s = "a good   example"
    // 输出："example good a"
    // 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
    printf("示例 3\n");
    char c3[] = "a good   example";
    res = reverseWords(c3);
    printf("res: %s\n", res);
    free(res);
    return 0;
}