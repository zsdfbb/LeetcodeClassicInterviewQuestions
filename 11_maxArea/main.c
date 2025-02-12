#include "stdio.h"
#include "stdlib.h"
#include "../common.h"

int cal_area(int* height, int left, int right)
{
    int h1 = height[left];
    int h2 = height[right];
    int min_h = MIN(h1, h2);
    return min_h * (right - left);
}

int maxArea(int* height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;
    int max = 0;

    while (left < right) {
        printf("left: %d, right: %d\n", left, right);
        // 1）当前面积
        max = MAX(max, cal_area(height, left, right));

        // 2）移动left， 计算面积
        int li = left + 1;
        while (li < right && height[li] <= height[left]) {
            li++;
        }
        if (li < right)
            max = MAX(max, cal_area(height, li, right));

        // 3）移动right, 计算面积
        int ri = right - 1;
        while (ri > left && height[ri] <= height[right]) {
            ri--;
        }
        if (ri > left)
            max= MAX(max, cal_area(height, left, ri));

        // 4）移动right 和 left，计算面积
        if (li < right && ri > left) {
            max = MAX(max, cal_area(height, li, ri));
        }
        

        left = li;
        right = ri;
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

    return 0;
}