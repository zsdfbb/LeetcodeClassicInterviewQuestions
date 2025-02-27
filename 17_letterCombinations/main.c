#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const char *map[10] = {
    "", //1
    "", //0
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs", // 7
    "tuv",
    "wxyz", // 9
};
const int map_count[10] = {0,0,3,3,3,3,3,4,3,4};

char** letterCombinations(char* digits, int* returnSize)
{
    if (digits == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int dl = strlen(digits);
    if (dl == 0) {
        *returnSize = 0;
        return NULL;
    }

    int res_sum = 1;
    for (int i = 0; i < dl; i++) {
        int n = digits[i] - '0';
        res_sum = res_sum * map_count[n]; 
    }
    *returnSize = res_sum;

    char **res = calloc(res_sum, sizeof(char *));
    for (int j = 0; j < res_sum; j++) {
        res[j] = calloc(dl + 1, sizeof(char));
    }

    int repeat_gap = res_sum;
    // i 指向第几个数字
    for (int i = 0; i < dl; i++) {
        //n 是i对应的map位置
        int n = digits[i] - '0';
        // j指向第几个结果
        repeat_gap = repeat_gap / map_count[n];
        // printf("repeat_gap: %d, map_count:%d\n", repeat_gap, map_count[n]);
        int cur_char_i = 0;
        for (int j = 0; j < res_sum; j++) {
            // map[i] 中的字母会重复出现， 出现的频率是 res_sum / map_count[i]
            if (j != 0 && j % repeat_gap == 0) {
                cur_char_i += 1;
                cur_char_i = cur_char_i % map_count[n];
            }
            // 第j个结果的第i的字符
            res[j][i] = map[n][cur_char_i];
        }
    }

    return res;
}

bool helper(char *digits, char *res, int i, char **all_res, int *all_res_count, int dl) {
    if (digits[0] == '\0') {
        // 是一个结果，可以使用res
        char *tmp = calloc(dl + 1, sizeof(char));
        strcpy(tmp, res);
        all_res[*all_res_count] = tmp;
        *all_res_count += 1; 
        return true;
    }

    int n = digits[0] - '0';
    char *str = map[n];
    int count = map_count[n];
    
    for (int j = 0; j < count; j++) {
        res[i] = str[j];
        helper(digits + 1, res, i + 1, all_res, all_res_count, dl);
    }

    return false;
}

char** letterCombinations_1(char* digits, int* returnSize)
{
    if (digits == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int dl = strlen(digits);
    if (dl == 0) {
        *returnSize = 0;
        return NULL;
    }

    int res_sum = 1;
    for (int i = 0; i < dl; i++) {
        int n = digits[i] - '0';
        res_sum = res_sum * map_count[n]; 
    }

    char **all_res = calloc(res_sum, sizeof(char *));
    char res[dl + 1];
    res[dl] = '\0';

    helper(digits, res, 0, all_res, returnSize, dl);

    return all_res;
}

int main()
{
    for (int i = 0; i < 10; i++) {
        printf("%d: %s %lu\n", i, map[i], strlen(map[i]));
        printf("%d: %d\n", i, map_count[i]);
        
    }

    
    char **res = NULL;
    int res_size = 0;

    char d1[] = "23";
    res = letterCombinations_1(d1, &res_size);
    for (int i = 0; i < res_size; i++) {
        printf("%s\n", res[i]);
        free(res[i]);
    }
    free(res);

    return 0;
}