#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    // 查找target
    int left = 0;
    int right = numsSize-1;
    int mid = 0;
    int find = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        int mid_val = nums[mid];
        // printf("%d: %d\n", mid, mid_val);
        if (target == mid_val) {
            find = 1;
            break;
        } else if (target > mid_val) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    // 处理结果
    int *res = malloc(sizeof(int) * 2);
    res[0] = -1; res[1] = -1;
    *returnSize = 2;

    if (find) {
        // 找到了
        int start = mid;
        int end = mid;
        while (start >= 0 && nums[start] == target) {
            start--;
        }
        while (end < numsSize && nums[end] == target) {
            end++;
        }

        res[0] = start + 1;
        res[1] = end - 1;
    }

    return res;
}

int main()
{
    int ret_size = 0;
    int n1[] = {5,7,7,8,8,10};
    int *res = searchRange(n1, sizeof(n1)/sizeof(int), 8, &ret_size);
    printf("%d %d\n\n", res[0], res[1]);

    int n2[] = {1,3};
    res = searchRange(n2, sizeof(n2)/sizeof(int), 1, &ret_size);
    printf("%d %d\n\n", res[0], res[1]);
    
    return 0;
}