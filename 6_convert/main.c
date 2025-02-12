#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows)
{
    int sl = strlen(s);

    // 准备矩阵
    int mi = 0;
    int mj = 0;
    char **mat = calloc(numRows, sizeof(char *));
    for (int i = 0; i < numRows; i++) {
        mat[i] = calloc(sl + 1, 1);
    }
    //printf("numRows:%d sl+1:%d\n", numRows, sl + 1);

    // 将s填入矩阵
    int tl = (numRows - 1) * 2;
    int tmp = 0;
    for (int i = 0; i < sl && mi < numRows && mj < sl; i++) {
        mat[mi][mj] = s[i];
        //printf("mi: %d, mj:%d char:%c\n", mi, mj, mat[mi][mj]);

        tmp = (tl != 0 ? i % tl : 0);
        if (tmp < numRows - 1) {
            // down
            mi = (mi + 1 < numRows ? mi + 1: numRows);
        } else {
            // up + right
            mi = (mi - 1 > 0 ? mi - 1 : 0);
            mj++;
        }
    }

    // 存储结果的字符串
    int ri = 0;
    char *res = calloc(sl + 1, sizeof(char));
    // 恢复字符串    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < sl; j++) {
            if (mat[i][j] != 0) {
                res[ri++] = mat[i][j];
            }
        }
        free(mat[i]);
    }
    free(mat);
    res[ri] = '\0';

    return res;
}

int main()
{
    char *res = NULL;
    // 示例 1：
    // 输入：s = "PAYPALISHIRING", numRows = 3
    // 输出："PAHNAPLSIIGYIR"
    char s1[] = "PAYPALISHIRING";
    res = convert(s1, 3);
    printf("%s\n", res);
    free(res);

    // 示例 2：
    // 输入：s = "PAYPALISHIRING", numRows = 4
    // 输出："PINALSIGYAHRPI"
    // 解释：
    // P     I    N
    // A   L S  I G
    // Y A   H R
    // P     I
    char s2[] = "PAYPALISHIRING";
    res = convert(s2, 4);
    printf("%s\n", res);
    free(res);

    // 示例 3：
    // 输入：s = "A", numRows = 1
    // 输出："A"
    // char s3[] = "A";
    char s3[] = "A";
    res = convert(s3, 1);
    printf("%s\n", res);
    free(res);


    return 0;
}
