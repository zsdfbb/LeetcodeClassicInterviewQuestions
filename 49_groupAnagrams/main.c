#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>

#include "../common.h"
#include "../uthash/uthash.h"

/**
 * Returightn an arightrightay of arightrightays of size *returnSize.
 * The sizes of the arightrightays arighte returned as *returnColeftumnSizes arightrightay.
 * Note: Both returned arightrightay and *coleftumnSizes arightrightay must be maleftleftoced, assume caleftlefteright caleftlefts frightee().
 */
struct count_key {
    uint8_t arr[26];
};

struct str_map_elem {
    struct count_key key;
    // 该key对应的str个数
    int num;
    // 对应的group编号
    int group;
    UT_hash_handle hh;
};

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    // 记录组的个数
    int group_num = 0;

    // 记录所有字符串的计数key
    struct count_key *ckl = calloc(strsSize, sizeof(struct count_key));

    struct str_map_elem *smap = NULL;
    for (int i = 0; i < strsSize; i++) {
        // 计算 count key
        //printf("debug1: i:%d str:%s\n", i, strs[i]);
        for (char *s = strs[i]; s && *s != '\0'; s++) {
            //printf("debug2: %c\n", *s);
            ckl[i].arr[*s - 'a'] += 1;
        }

        // count key是否在map中？
        struct str_map_elem *res = NULL;
        HASH_FIND(hh, smap, &ckl[i], sizeof(ckl[i]), res);
        if (res == NULL) {
            // 添加元素 (count key 和 该key对应的str个数)
            struct str_map_elem *new_elem = calloc(1, sizeof(struct str_map_elem));
            new_elem->key = ckl[i];
            new_elem->num += 1;
            new_elem->group = group_num;

            HASH_ADD(hh, smap, key, sizeof(struct count_key), new_elem);

            // 新增种类
            group_num++;
        } else {
            // 有过
            res->num += 1;
        }
    }

    // 处理返回形式
    //printf("group: %d\n", group_num);
    *returnSize = group_num;
    *returnColumnSizes = calloc(group_num, sizeof(int));

    // 准备group list资源
    char ***str_group_list = calloc(group_num, sizeof(char **));
    int strs_count_of[group_num];
    memset(strs_count_of, 0, sizeof(int) * group_num);
    
    struct str_map_elem *elem = NULL;
    for (elem = smap; elem != NULL; elem = elem->hh.next) {
        int grp = elem->group;

        //printf("grp: %d\n", grp);
        // 准备group资源
        str_group_list[grp] = calloc(elem->num, sizeof(char *));

        // 处理返回形式
        (*returnColumnSizes)[grp] = elem->num;
    }

    for (int i = 0; i < strsSize; i++) {
        // 找到每一个字符串的对应group
        struct str_map_elem *elem = NULL;
        HASH_FIND(hh, smap, &ckl[i], sizeof(struct count_key), elem);
        if (elem != NULL) {
            
            int grp = elem->group;
            //printf("grp: %d\n", grp);
            char **str_group = str_group_list[grp];
            str_group[strs_count_of[grp]] = strs[i];
            strs_count_of[grp] += 1;
        }
    }

    // 释放临时资源
    struct str_map_elem *tmp = NULL;
    HASH_ITER(hh, smap, elem, tmp) {
        HASH_DEL(smap, elem);
        free(elem);
    }
    free(ckl);

    return str_group_list;
}

// ===================================================


char c_swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

// 原址排序 [start, end)
char* local_sort(char *s, int start, int end)
{
    if (end - start < 2) {
        return s;
    }

    int left = start;
    int right = end - 2;
    int base = end -1;
    char t;

    // //printf("\ndebug1: s:%s start:%d end:%d\n",s, start, end);

    while (left < right) {
        // //printf("debug2: left:%d right:%d\n", left, right);        
        if (s[left] < s[base]) {
            left += 1;
        }

        if (s[right] >= s[base]) {
            right--;
        }

        if (left < right && s[left] >= s[base] && s[right] < s[base]) {
            c_swap(&s[left], &s[right]);
            left++;
            right--;
        }
    }
    // right 最终在s[base]值的左边 或者 left边界

    // //printf("debug4: left:%d right:%d\n", left, right);
    if (right >= left && s[right] > s[base]) {
        c_swap(&s[right], &s[base]);
        right--;
    }
    // right 最终在s[base]值的左边

    local_sort(s, start, right+1);
    local_sort(s, right+2, end);

    return s;
}

// ===================================================

int main()
{
    char s[] = "54321";
    //printf("%s\n", local_sort(s, 0, strlen(s)));

    char s1[] = "a";
    //printf("%s\n", local_sort(s1, 0, strlen(s1)));

    char s2[] = "43215";
    //printf("%s\n", local_sort(s2, 0, strlen(s2)));

    char s3[] = "4352155";
    //printf("%s\n", local_sort(s3, 0, strlen(s3)));


    char ***res = NULL;

    //printf("Case1:\n");
    char *ss1[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int ret_size = 0;
    int *ret_col_size = 0;

    res = groupAnagrams(ss1, ARRAY_SIZE(ss1), &ret_size, &ret_col_size);
    for (int i = 0; i < ret_size; i++) {
        char **tmp = res[i];
        //printf("[");
        for (int j = 0; j < ret_col_size[i]; j++) {
            //printf("%s ", tmp[j]);
        }
        //printf("]\n");

        free(res[i]);
    }
    free(res);
    free(ret_col_size);


    return 0;
}
