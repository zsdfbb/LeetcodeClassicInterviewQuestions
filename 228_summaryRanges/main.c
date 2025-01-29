#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

void debug_info(int *range, int rl)
{
    for (int i = 0; i < rl; i++) {
        printf("%d ", range[i]);
    }
    printf("\n");
}

void range_info(char **ranges, int ranges_size)
{
    for (int i = 0; i < ranges_size; i++) {
        printf("%s\n", ranges[i]);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize)
{
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // 获得区间列表
    int ri = 0;
    int *rangelist = calloc(numsSize + 1, sizeof(int));
    int i = 0;
    for (i = 0; i < numsSize - 1; i++) {
        bool split = (nums[i] + 1 != nums[i + 1]);
        if (split) {
            rangelist[ri] = i;
            ri++;
        }
    }
    rangelist[ri++] = i;
    int rl_size = ri;
    // debug_info(rangelist, ri);

    // 获得区间对 列表
    int *pair_list = calloc(rl_size << 1, sizeof(int));
    int pl_size = 0;
    for (int i = 0; i < rl_size; i++) {
        int p1 = (i > 0 ? rangelist[i - 1] + 1 : 0);
        int p2 = rangelist[i];
        pair_list[i << 1] = p1;
        pair_list[(i << 1) + 1] = p2;
        pl_size += 1;
        // printf("%d %d\n", p1, p2);
    }

    char **res = calloc(pl_size, sizeof(char *));
    for (int i = 0; i < pl_size; i++) {
        res[i] = (char *)calloc(64, 1);
        if (pair_list[i << 1] == pair_list[(i << 1) + 1]) {
            int ni = pair_list[i << 1];
            snprintf(res[i], 64, "%d", nums[ni]);
        } else {
            int ni1 = pair_list[i << 1];
            int ni2 = pair_list[(i << 1) + 1];
            snprintf(res[i], 64, "%d->%d", nums[ni1], nums[ni2]);
        }
    }
    *returnSize = pl_size;
    return res;
}



int main()
{
    // 示例 1：
    // 输入：nums = [0,1,2,4,5,7]
    // 输出：["0->2","4->5","7"]
    // 解释：区间范围是：
    // [0,2] --> "0->2"
    // [4,5] --> "4->5"
    // [7,7] --> "7"
    printf("\ntest:\n");
    int nums1[] = {0,1,2,4,5,7};
    int retsize1 = 0;
    char **res1 = summaryRanges(nums1, sizeof(nums1)/sizeof(nums1[0]), &retsize1);
    range_info(res1, retsize1);

    // 示例 2：
    // 输入：nums = [0,2,3,4,6,8,9]
    // 输出：["0","2->4","6","8->9"]
    // 解释：区间范围是：
    // [0,0] --> "0"
    // [2,4] --> "2->4"
    // [6,6] --> "6"
    // [8,9] --> "8->9"
    printf("\ntest:\n");
    int nums2[] = {0,2,3,4,6,8,9};
    int retsize2 = 0;
    char **res2 = summaryRanges(nums2, sizeof(nums2)/sizeof(nums2[0]), &retsize2);
    range_info(res2, retsize2);

    return 0;
}