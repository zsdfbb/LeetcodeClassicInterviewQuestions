#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// 方法一：反向查找出发位置
// 如果有多个位置通过跳跃都能够到达最后一个位置，那么我们应该如何进行选择呢？直观上来看，
// 我们可以「贪心」地选择距离最后一个位置最远的那个位置，也就是对应下标最小的那个位置。
// 因此，我们可以从左到右遍历数组，选择第一个满足要求的位置。
int jump(int* nums, int numsSize)
{
    int position = numsSize - 1;
    int times = 0;

    while (position > 0) {
        for (int i = 0; i < position; i++) {
            if (i + nums[i] >= position) {
                position = i;
                times++;
                break;
            }
        }
    }
    return times;
}

// 方法二：正向查找可到达的最大位置
int jump1(int* nums, int numsSize)
{
    int times = 0;
    int max = nums[0];
    int border;
    int i = 0;

    while(i < numsSize-1) {
        border = max;
        while (i < border && i < numsSize-1) {
            i++;
            max = (max > i+nums[i] ? max : i+nums[i]);
        }
        times++;
    }

    return times;
}

int jump2(int* nums, int numsSize)
{
    int times = 0;
    int max = 0;
    int border = 0;

    for(int i = 0; i < numsSize-1; i++) {
        int t = i + nums[i];
        max = (max >  t ? max : t);

        if (i == border) {
            border = max;
            times++;
        }
    }

    return times;
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
int main()
{
    // 示例 1：
    // 输入：nums = [2,3,1,1,4]
    // 输出：true
    // 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
    int n1[] = {2,3,1,1,4};
    printf("%d\n", jump(n1, ARRAY_SIZE(n1)));
    printf("%d\n", jump2(n1, ARRAY_SIZE(n1)));

    // 示例 2：
    // 输入：nums = [2,3,0,1,4]
    // 输出：false
    // 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
    int n2[] = {2,3,0,1,4};
    printf("%d\n", jump(n2, ARRAY_SIZE(n2)));
    printf("%d\n", jump2(n2, ARRAY_SIZE(n2)));

    return 0;
}