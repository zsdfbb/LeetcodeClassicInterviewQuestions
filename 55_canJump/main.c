#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

bool canJump(int* nums, int numsSize)
{
    int res = false;
    int max = 0;
    int i = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > max) {
            break;
        }

        int tmp = i + nums[i];
        max = (max > tmp ? max : tmp);
        if (max >= numsSize - 1) {
            res = true; break;
        }
    }

    return res;
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
int main()
{
    
    // 示例 1：
    // 输入：nums = [2,3,1,1,4]
    // 输出：true
    // 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
    int n1[] = {2,3,1,1,4};
    printf("%d\n", canJump(n1, ARRAY_SIZE(n1)));

    // 示例 2：
    // 输入：nums = [3,2,1,0,4]
    // 输出：false
    // 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
    int n2[] = {3,2,1,0,4};
    printf("%d\n", canJump(n2, ARRAY_SIZE(n2)));

    // 示例 3：
    // 输入：nums = [0]
    // true
    // 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
    int n3[] = {0};
    printf("%d\n", canJump(n3, ARRAY_SIZE(n3)));


    // 示例 4：
    // 输入：nums = [1,2]
    // true
    int n4[] = {1,2};
    printf("%d\n", canJump(n4, ARRAY_SIZE(n4)));

    // 输入：nums = [0,1]
    // false
    int n5[] = {0,1};
    printf("%d\n", canJump(n5, ARRAY_SIZE(n5)));
}