#include "stdio.h"
#include "stdlib.h"
#include "../common.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;
    int min_i = 0;
    int max = 0;

    while (left < right) {
        // printf("left: %d, right: %d\n", left, right);
        int hl = height[left];
        int hr = height[right];
        if (hl < hr) {
            max = MAX(max, hl * (right - left));
            left++;
        } else {
            max = MAX(max, hr * (right - left));
            right--;
        }
    }

    return max;
}

int main()
{
    int ret = 0;
    // 示例 1：
    // 输入：[1,8,6,2,5,4,8,3,7]
    // 输出：49 
    // 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。
    // 在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
    int h1[] = {1,8,6,2,5,4,8,3,7};
    printf("%d\n", maxArea(h1, ARRAY_SIZE(h1)));

    // 示例 2：
    // 输入：height = [1,1]
    // 输出：1
    int h2[] = {1,1};
    printf("%d\n", maxArea(h2, ARRAY_SIZE(h2)));

    // 示例 2：
    // 输入：height = [8,7,6,5]
    // 输出：7
    int h3[] = {8,7,2,1};
    printf("%d\n", maxArea(h3, ARRAY_SIZE(h3)));

    return 0;
}