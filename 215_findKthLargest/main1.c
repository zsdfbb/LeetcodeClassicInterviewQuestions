#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MIN_VAL -10001
#define MAX_VAL 10001

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

bool maxheap_swap(int *max, int *min)
{
    if (*max < *min) {
        int t = *max;
        *max = *min;
        *min = t;
        return true;
    }
    return false;
}

void maxheap_print(int *maxheap)
{
    printf("count: %d\n", maxheap[0]);
    for (int i = 1; i <= maxheap[0]; i++) {
        printf("%d ", maxheap[i]);
    }
    printf("\n");
}

void maxheap_build(int *maxheap)
{
    int heapsize = maxheap[0];
    // printf("heapsize: %d\n", heapsize);
    for (int i = heapsize / 2; i >= 1; i--) {
        // printf("i: %d\n", i);
        if ((2 * i) <= heapsize) {
            // printf("try swap: %d %d\n", i, 2*i);
            maxheap_swap(&maxheap[i], &maxheap[2 * i]);
        }
        if ((2 * i + 1) <= heapsize) {
            // printf("try swap: %d %d\n", i, 2*i+1);
            maxheap_swap(&maxheap[i], &maxheap[2 * i + 1]);
        }
    }
}

int maxheap_extract(int *maxheap)
{
    int count = maxheap[0];
    int maxval = maxheap[count];
    if (count < 2) {
        return maxval;
    }

    swap(&maxheap[1], &maxheap[count]);
    count -= 1;
    maxheap[0] = count;

    maxheap_build(maxheap);

    return maxval;
}


int findKthLargest(int* nums, int numsSize, int k)
{
    // 初始化
    int *maxheap = calloc(numsSize + 1, sizeof(int));
    maxheap[0] = numsSize;
    for (int i = 0; i < numsSize; i++) {
        maxheap[i + 1] = nums[i];
    }

    // 构建堆
    maxheap_build(maxheap);
    maxheap_print(maxheap);

    // 提取k次
    for (int t = 0; t < k; t++) {
        maxheap_extract(maxheap);
        maxheap_print(maxheap);
    }

    return maxheap[numsSize - k + 1];
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