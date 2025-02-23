#include <stdlib.h>
#include <stdbool.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
    int left = 0;
    int right = k;

    for (int i = 0; i < numsSize -k + 1; i++) {

    }
}

// 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个不同的索引 i 和 j，
// 满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
// 如果存在，返回 true ；否则，返回 false 。
int main()
{

    // 示例 1：
    // 输入：nums = [1,2,3,1], k = 3
    // 输出：true

    // 示例 2：
    // 输入：nums = [1,0,1,1], k = 1
    // 输出：true

    // 示例 3：
    // 输入：nums = [1,2,3,1,2,3], k = 2
    // 输出：false

    return 0;
}