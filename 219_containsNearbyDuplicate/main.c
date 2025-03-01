#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../uthash/uthash.h"

typedef struct int_map {
    int num;
    struct UT_hash_handle hh;
} int_map_t;

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
    if (k == 0) {
        return false;
    }

    int left = 0;
    int right = k;
    int_map_t *imap = NULL;
    int_map_t *ie = NULL;

    //printf("debug1\n");
    for (int i = 0; i < numsSize && i <= k; i++) {
        HASH_FIND_INT(imap, &nums[i], ie);
        if (ie == NULL) {
            //printf("add i:%d num:%d\n", i, nums[i]);
            ie = malloc(sizeof(int_map_t));
            ie->num = nums[i];
            HASH_ADD_INT(imap, num, ie);
        } else {
            //printf("ret i:%d num:%d\n", i, nums[i]);
            return true;
        }
    }

    //printf("debug2\n");
    int_map_t *tmp = NULL;
    for (int i = k+1; i < numsSize; i++) {
        // 删除旧节点
        HASH_FIND_INT(imap, &nums[i-k-1], tmp);
        //printf("del ie: %d\n", ie->num);
        HASH_DEL(imap, tmp);
        // 添加新节点, 进行判断
        HASH_FIND_INT(imap, &nums[i], ie);
        if (ie == NULL) {
            //printf("add i:%d num:%d\n", i, nums[i]);
            // 复用tmp的内存
            ie = tmp;
            ie->num = nums[i];
            HASH_ADD_INT(imap, num, ie);
        } else {
            return true;
        }
    }
    return false;
}

// 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个不同的索引 i 和 j，
// 满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
// 如果存在，返回 true ；否则，返回 false 。
int main()
{
    // 示例 1：
    // 输入：nums = [1,2,3,1], k = 3
    // 输出：true
    int n1[] = {1,2,3,1};
    printf("%d\n\n", containsNearbyDuplicate(n1, sizeof(n1)/sizeof(int), 3));

    // 示例 2：
    // 输入：nums = [1,0,1,1], k = 1
    // 输出：true
    int n2[] = {1,0,1,1};
    printf("%d\n\n", containsNearbyDuplicate(n2, sizeof(n2)/sizeof(int), 1));

    // 示例 3：
    // 输入：nums = [1,2,3,1,2,3], k = 2
    // 输出：false
    int n3[] = {1,2,3,1,2,3};
    printf("%d\n\n", containsNearbyDuplicate(n3, sizeof(n3)/sizeof(int), 2));

    return 0;
}