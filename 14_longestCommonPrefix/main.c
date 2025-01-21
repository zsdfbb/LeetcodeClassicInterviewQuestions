#include <stdio.h>
#include <memory.h>


// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] 如果非空，则仅由小写英文字母组成
char* longestCommonPrefix(char** strs, int strsSize)
{
    #define MAX_STR_LEN 256
    static char res_str[MAX_STR_LEN];
    memset(res_str, 0, MAX_STR_LEN);

    // 最短字符串
    int min_str_len = MAX_STR_LEN;
    int min_str_index = 0;
    for (int i = 0; i < strsSize; i++) {
        // 空字符串，无公共前缀，直接结束
        if (strs[i] == NULL) {
            return "";
        }

        int str_i_len = strlen(strs[i]);
        if (str_i_len < min_str_len) {
            min_str_index = i;
            min_str_len = str_i_len;
        }
    }

    // i遍历最短字符串的每个字符
    char *min_str = strs[min_str_index];
    for (int i = 0; i < min_str_len; i++) {
        char c = min_str[i];
        // j遍历所有字符串
        for (int j = 0; j < strsSize; j++) {
            if (c != strs[j][i]) {
                return res_str;
            }
        }
        res_str[i] = c;
    }
    return res_str;
}

int main()
{
    char *res = NULL;

    char *strs1[] = {"flower","flow","flight"};
    res = longestCommonPrefix(strs1, 3);
    printf("result: %s\n", res);


    char *strs2[] = {"dog","racecar","car"};
    res = longestCommonPrefix(strs2, 3);
    printf("result: %s\n", res);

    char *strs3[] = {"reflower","flow","flight"};
    res = longestCommonPrefix(strs3, 3);
    printf("result: %s\n", res);
}
