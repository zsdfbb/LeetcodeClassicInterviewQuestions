#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

bool isValid(char *s)
{
    bool res = false;
    int sl = strlen(s);

    int top = -1;
    char stack[sl + 1];
    int i = 0;
    for (i = 0; i < sl; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            top++;
            stack[top] = s[i];
        }

        if (s[i] == ')') {
            if (top >= 0 && stack[top] == '(') {
                stack[top] = '\0';
                top--;
            } else {
                res = false;
                break;
            }
        }

        if (s[i] == '}') {
            if (top >= 0 && stack[top] == '{') {
                stack[top] = 0;
                top--;
            } else {
                res = false;
                break;
            }
        }

        if (s[i] == ']') {
            if (top >= 0 && stack[top] == '[') {
                stack[top] = 0;
                top--;
            } else {
                res = false;
                break;
            }
        }
    }
    if (top == -1 && i == sl) {
        res = true;
    }

    return res;
}

int main()
{
    // 示例 1：
    // 输入：s = "()"
    // 输出：true
    char s1[] =  "()";
    printf("%d\n", (int)isValid(s1));

    // 示例 2：
    // 输入：s = "()[]{}"
    // 输出：true
    char s2[] =  "()[]{}";
    printf("%d\n", (int)isValid(s2));

    // 示例 3：
    // 输入：s = "(]"
    // 输出：false
    char s3[] =  "(]";
    printf("%d\n", (int)isValid(s3));


    // 示例 4：
    // 输入：s = "([])"
    // 输出：true
    char s4[] =  "([])";
    printf("%d\n", (int)isValid(s4));


    // 示例 5：
    // 输入：s = "]"
    // 输出：false
    char s5[] =  "]";
    printf("%d\n", (int)isValid(s5));

    return 0;
}