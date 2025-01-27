#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int minSubArrayLen(int target, int *nums, int numsSize)
{
    int l = 0;
    int r = 0;
    int min_l = numsSize + 1;
    int sum = 0;
    int tmp_len = 0;

    while (l < numsSize && r < numsSize) {
        if (sum < target ) {
            // printf("%d %d %d\n", l, r, sum);
            // right 向前移动，尝试获取更长的子数组，以满足 sum >= target
            sum += nums[r];
            r++;
        }
        if (sum >= target) {
            // printf("%d %d %d\n", l, r, sum);
            // 记录满足条件的数组长度
            tmp_len = r - l;
            min_l = (tmp_len < min_l ? tmp_len : min_l);

            // left 向前移动，尝试获取更短的子数组
            sum -= nums[l];
            l++;
        }
    }

    // right 已经走到末尾，但是sum依然比target要大，可以继续尝试缩短数组
    while (l < numsSize && sum >= target) {
        // printf("%d %d %d\n", l, r, sum);
        // 记录满足条件的数组长度
        tmp_len = r - l;
        min_l = (tmp_len < min_l ? tmp_len : min_l);

        // left 向前移动，尝试获取更短的子数组
        sum -= nums[l];
        l++;
    }

    if (min_l == numsSize + 1) {
        min_l = 0;
    }
    return min_l;
}

int main()
{

    // 示例 1：
    // 输入：target = 7, nums = [2,3,1,2,4,3]
    // 输出：2
    // 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
    int target1 = 7;
    int nums1[] = {2,3,1,2,4,3};
    printf("%d\n", minSubArrayLen(target1, nums1, sizeof(nums1)/sizeof(nums1[0])));

    // 示例 2：
    // 输入：target = 4, nums = [1,4,4]
    // 输出：1
    int target2 = 4;
    int nums2[] = {1,4,4};
    printf("%d\n", minSubArrayLen(target2, nums2, sizeof(nums2)/sizeof(nums2[0])));


    // 示例 3：
    // 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
    // 输出：0
    int target3 = 11;
    int nums3[] = {1,1,1,1,1,1,1,1};
    printf("%d\n", minSubArrayLen(target3, nums3, sizeof(nums3)/sizeof(nums3[0])));

    return 0;
}