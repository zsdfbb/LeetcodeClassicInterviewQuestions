#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// 字符串原地反转
int reverse(char *str)
{
    int sl = strlen(str);
    char t = 0;
    for (int i = 0; i < sl / 2; i++) {
        t = str[i];
        str[i] = str[sl - 1 - i];
        str[sl - 1 - i] = t;
    }
    return sl;
}

char *addBinary(char *a, char *b)
{
    // 将 a和b反转，低位作为索引起始
    int al = reverse(a);
    int bl = reverse(b);
    int maxl = MAX(al, bl);
    char *res = calloc(maxl << 2, 1);

    // 从头开始计算 a 和 b 的二进制相加
    char carry = '0';
    char csum = '0';
    for (int i = 0; i < maxl; i++) {
        char ca = (i < al ? a[i] : '0');
        char cb = (i < bl ? b[i] : '0');

        // a + b + carry = ?
        // 1 + 1 + 1 = 1 (carry = 1)
        // 1 + 0 + 1 = 0 (carry = 1)
        // 0 + 1 + 1 = 0 (carry = 1)
        // 0 + 0 + 1 = 1 (carry = 0)
        // 1 + 1 + 0 = 0 (carry = 1)
        // 1 + 0 + 0 = 1 (carry = 0)
        // 0 + 1 + 0 = 1 (carry = 0)
        // 0 + 0 + 0 = 0 (carry = 0)
        int sum = 0;
        sum = (ca == '1' ? sum + 1: sum);
        sum = (cb == '1' ? sum + 1: sum);
        sum = (carry == '1' ? sum + 1: sum);
        carry = (sum > 1 ? '1' : '0');
        csum = (sum % 2 == 1 ? '1' : '0');
        res[i] = csum;
    }

    if (carry == '1') {
        res[maxl] = '1';
    }
    
    reverse(res);
    return res;
}

int main()
{
    printf("===== test1\n");
    char a1[32] = "1010";
    char b1[32] = "1011";
    char *res1 = addBinary(a1, b1);
    printf("%s + %s = %s\n", a1, b1, res1);
    free(res1);


    printf("===== test2\n");
    char a2[3] = "1";
    char b2[3] = "11";
    char *res2 = addBinary(a2, b2);
    printf("%s + %s = %s\n", a2, b2, res2);
    free(res2);

    return 0;
}