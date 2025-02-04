#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

static inline void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heap_fixup(int *nums, int i, int numsSize)
{
    int mi = i;
    int li = 2 * i + 1;
    int ri = 2 * i + 2;
    if (li < numsSize && nums[li] > nums[mi]) {
        mi = li;
    }

    if (ri < numsSize && nums[ri] > nums[mi]) {
        mi = ri;
    }

    if (i != mi) {
         swap(&nums[mi], &nums[i]);
         // nums[mi] 变小了，需要重新计算子树的最大值
         heap_fixup(nums, mi, numsSize);
    }
}

void heap_build(int *nums, int numsSize)
{
    for (int i = numsSize / 2 - 1; i >= 0; i--) {
        heap_fixup(nums, i, numsSize);
    }
}

int findKthLargest(int* nums, int numsSize, int k)
{
    // 初始化
    heap_build(nums, numsSize);

    for (int t = 0; t < k; t++) {
        swap(&nums[0], &nums[numsSize - 1 - t]);
        heap_fixup(nums, 0, numsSize - 1 - t);
    }

    return nums[numsSize - k];
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
int main()
{
    int ret = 0;
    // 示例 1:
    // 输入: [3,2,1,5,6,4], k = 2
    // 输出: 5
    printf("\ntest\n");
    int nums1[] = {3,2,1,5,6,4};
    ret = findKthLargest(nums1, ARRAY_SIZE(nums1), 2);
    printf("result: %d\n", ret);


    // 示例 2:
    // 输入: [3,2,3,1,2,4,5,5,6], k = 4
    // 输出: 4
    printf("\ntest\n");
    int nums2[] = {3,2,3,1,2,4,5,5,6};
    ret = findKthLargest(nums2, ARRAY_SIZE(nums2), 4);
    printf("result: %d\n", ret);

    return 0;
}