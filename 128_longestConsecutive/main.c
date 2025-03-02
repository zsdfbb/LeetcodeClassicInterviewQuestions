#include <stdio.h>
#include <stdlib.h>

#include "../uthash/uthash.h"

typedef struct int_set {
    int val;
    int count;
    UT_hash_handle hh;
} int_set_t;

int longestConsecutive(int* nums, int numsSize)
{
    int_set_t *iset = NULL;
    int_set_t *cur = NULL;
    int_set_t *iter_tmp = NULL;
    int_set_t *tmp = NULL;

    int_set_t *iset_elems = malloc(numsSize * sizeof(int_set_t));
    // printf("%p\n", iset_elems);
    int elem_i = 0;

    for (int i = 0; i < numsSize; i++) {
        int_set_t *tmp = 0;
        HASH_FIND_INT(iset, &nums[i], tmp);
        if (tmp == NULL) {
            // printf("add: %d\n", nums[i]);
            int_set_t *new = &iset_elems[elem_i++];
            // printf("%p\n", new);
            new->val = nums[i];
            new->count = 0;
            HASH_ADD_INT(iset, val, new);
        }        
    }

    int maxl = 0;
    HASH_ITER(hh, iset, cur, iter_tmp) {
        int val = cur->val -1;
        HASH_FIND_INT(iset, &val, tmp);
        if (tmp != NULL) {
            // 找到了 cur_val - 1
            // cur_val 会被比他小的 cur_val - 1 遍历，直接跳过
            continue;
        }

        int j = 1;
        while(1) {
            val = cur->val + j;
            // printf("find: val: %d\n", val);
            HASH_FIND_INT(iset, &val, tmp);
            if (tmp == NULL) {
                break;
            }
            tmp->count = 1;
            j++;
        }
        maxl = (maxl > j ? maxl : j);
    }

    free(iset_elems);
    return maxl;
}

#include "../common.h"

int main()
{
    // int n1[] = {99999,99998,99997,99996,99995,99994,99993,99992};
    // printf("%d\n",longestConsecutive(n1, ARRAY_SIZE(n1)));

    // int n2[] = {0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7};
    // printf("%d\n",longestConsecutive(n2, ARRAY_SIZE(n2)));

    int n1[] = {100,4,200,1,3,2};
    printf("%d\n",longestConsecutive(n1, ARRAY_SIZE(n1)));


    return 0;
}