#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// 0 1 2 3
// 1 3 5 6
// 2 或 7
int searchInsert(int* nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        printf("mid = %d\n", mid);
        if (nums[mid] == target) {
            l = mid;
            break;
        }
        if (nums[mid] < target) {
            l = mid + 1;
        }
        if (nums[mid] > target) {
            r = mid - 1;
        }
    }

    return l;
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
int main()
{
    int ret = 0;
    // 示例 1:
    // 输入: nums = [1,3,5,6], target = 5
    // 输出: 2
    printf("\ntest\n");
    int nums1[] = {1,3,5,6};
    int target1 = 5;
    ret = searchInsert(nums1, ARRAY_SIZE(nums1), target1);
    printf("index: %d\n", ret);

    // 示例 2:
    // 输入: nums = [1,3,5,6], target = 2
    // 输出: 1
    printf("\ntest\n");
    int nums2[] = {1,3,5,6};
    int target2 = 2;
    ret = searchInsert(nums2, ARRAY_SIZE(nums2), target2);
    printf("index: %d\n", ret);

    // 示例 3:
    // 输入: nums = [1,3,5,6], target = 7
    // 输出: 4
    printf("\ntest\n");
    int nums3[] = {1,3,5,6};
    int target3 = 7;
    ret = searchInsert(nums3, ARRAY_SIZE(nums3), target3);
    printf("index: %d\n", ret);

    // 示例 4:
    // 输入: nums = [1,3,5], target = 3
    // 输出: 0
    printf("\ntest\n");
    int nums4[] = {1,3,5};
    int target4 = 3;
    ret = searchInsert(nums4, ARRAY_SIZE(nums4), target4);
    printf("index: %d\n", ret);
}