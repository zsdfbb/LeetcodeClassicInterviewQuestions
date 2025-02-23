#include "stdlib.h"
#include "stdio.h"
#include "../uthash/uthash.h"
#include <stdio.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct str_map {
    char *key;
    int index;
    UT_hash_handle hh;
};

// 原址排序
char* sort(char *s, int start, int end)
{
    if (end - start < 2) {
        return s;
    }

    int l = start;
    int r = end - 2;
    int base = end -1;
    char t;

    printf("debug1: s:%s start:%d end:%d\n",s, start, end);

    while (l < r) {
        printf("debug2: l:%d r:%d\n", l, r);
        while (l < r && s[l] < s[base]) {
            l++;
        }

        while (l < r && s[r] >= s[base]) {
            r--;
        }

        if (s[l] >= s[base] && s[r] < s[base])  {
            printf("debug3: l:%d r:%d\n", l, r);
            t = s[l];
            s[l] = s[r];
            s[r] = t;
        }
    }

    printf("debug4: l:%d r:%d\n", l, r);
    if (s[r] > s[base]) {
        t = s[r];
        s[r] = s[base];
        s[base] = t;
    } else {
        sort(s, start, r + 1);
        sort(s, r + 1, end);
    }

    return s;
}

char*** groupAnagrams(char** strs, int strsSize,
                        int* returnSize, int** returnColumnSizes)
{
    struct str_map *smap = NULL;

    // 排序

    return NULL;
}

int main()
{
    char s[] = "54321";
    printf("%s\n", sort(s, 0, strlen(s)));
    return 0;
}