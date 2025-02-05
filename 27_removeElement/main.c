#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>


int removeElement(int* nums, int numsSize, int val)
{
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            nums[i] = -1;
        }
    }

    int slow = 0;
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] == -1)
            continue;

        nums[slow] =  nums[fast];
        slow++;
    }

    return slow;
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
int main()
{
    // 示例 1：
    // 输入：nums = [3,2,2,3], val = 3
    // 输出：2, nums = [2,2,_,_]
    // 解释：你的函数函数应该返回 k = 2, 并且 nums 中的前两个元素均为 2。
    // 你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
    int nums1[] = {3,2,2,3};
    int ret = removeElement(nums1, ARRAY_SIZE(nums1), 3);
    printf("%d\n", ret);

    // 示例 2：
    // 输入：nums = [0,1,2,2,3,0,4,2], val = 2
    // 输出：5, nums = [0,1,4,0,3,_,_,_]
    // 解释：你的函数应该返回 k = 5，并且 nums 中的前五个元素为 0,0,1,3,4。
    // 注意这五个元素可以任意顺序返回。
    // 你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
    int nums2[] = {0,1,2,2,3,0,4,2};
    ret = removeElement(nums2, ARRAY_SIZE(nums2), 2);
    printf("%d\n", ret);
}