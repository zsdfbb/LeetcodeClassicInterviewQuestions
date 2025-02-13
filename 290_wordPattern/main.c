#include "stdbool.h"
#include "string.h"
#include "memory.h"

#include "../common.h"
#include "../uthash/uthash.h"
// https://troydhanson.github.io/uthash/userguide.html

struct str_map_st {
    const char *key;
    char p;
    UT_hash_handle hh;
};

bool wordPattern(char* pattern, char* s)
{
    int p_map_size = (int)'z' + 1;
    int p_cmp_i = 0;
    char *p_map[p_map_size];
    memset(p_map, 0, sizeof(char *) * p_map_size);
    int pl = strlen(pattern);

    struct str_map_st *str_map = NULL;
    struct str_map_st *str_map_elem = NULL;

    const char sep = ' ';
    char p = 0;
    char *word = NULL;
    for (word = strtok(s, &sep); word; word = strtok(NULL, &sep)) {
        // pattern 字符
        if (p_cmp_i >= pl) {
            return false;
        }
        p = pattern[p_cmp_i++];
    
        // printf("word: %s, p: %c\n", word, p);

        // word 是否在map中?
        HASH_FIND_STR(str_map, word, str_map_elem);
        if (str_map_elem == NULL) {
            str_map_elem = (struct str_map_st *)malloc(sizeof(*str_map_elem));
            str_map_elem->key = word;
            str_map_elem->p = p;

            // word: fish, p: a
            if (p_map[p] != NULL) {
                struct str_map_st *tmp = NULL;
                // p_map[p]: dog
                HASH_FIND_STR(str_map, p_map[p], tmp);
                if (tmp != NULL) {
                    return false;
                }
            } else {
                p_map[p] = word;
            }

            HASH_ADD_KEYPTR(hh, str_map, word, strlen(word), str_map_elem);
        } else {
            if (str_map_elem->p != p) {
                return false;
            }
        }
    }

    if (pattern[p_cmp_i] != '\0') {
        return false;
    }

    return true;
}

int main()
{
    bool res = 0;
    // 示例1:
    // 输入: pattern = "abba", s = "dog cat cat dog"
    // 输出: true
    char p1[] = "abba";
    char s1[] = "dog cat cat dog";
    res = wordPattern(p1, s1);
    printf("res: %d\n", (int)res);

    // 示例 2:
    // 输入:pattern = "abba", s = "dog cat cat fish"
    // 输出: false
    char p2[] = "abba";
    char s2[] = "dog cat cat fish";
    res = wordPattern(p2, s2);
    printf("res: %d\n", (int)res);


    // 示例 3:
    // 输入: pattern = "aaaa", s = "dog cat cat dog"
    // 输出: false
    char p3[] = "aaaa";
    char s3[] = "dog cat cat dog";
    res = wordPattern(p3, s3);
    printf("res: %d\n", (int)res);


    // 示例 4:
    // 输入: pattern = "abba", s = "dog dog dog dog"
    // 输出: false
    char p4[] = "abba";
    char s4[] = "dog dog dog dog";
    res = wordPattern(p4, s4);
    printf("res: %d\n", (int)res);
}