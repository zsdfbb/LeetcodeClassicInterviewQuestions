#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// 最大公约数（Greatest Common Divisor，GCD
// 辗转相除法
int gcd(int a, int b)
{
    int m = 0;
    while(b != 0) {
        m = a % b;
        a = b;
        b = m;
    }
    return a;
}

void swap(int *a, int *b)
{
    int t = *b;
    *b = *a;
    *a = t;
}

// 1 2 3 4 5 6  | 1 2 3 4 5 6  | 1 2 3 4 5 6
// nums[] = {1 2 3 4 5 6 } -> {3 4 5 6 1 2}
// k = 4
// 1 -> 5 -> 3 -> 1(起点)
// 2 -> 6 -> 4 -> 2(起点)
void rotate(int* nums, int numsSize, int k)
{
    k = k % numsSize;

    int times = gcd(numsSize, k);
    for (int start = 0; start < times; start++) {
        int cur = start;
        int cur_val = nums[cur];
        int next = 0;
        do {
            next = (cur + k) % numsSize;
            swap(&cur_val, &nums[next]);
            cur = next;
        } while (cur != start);
    }
}

void rotate1(int* nums, int numsSize, int k)
{
    int arr[numsSize];
    int ai = 0;

    // 避免 k 比 numsSize大
    k = k % numsSize;

    // 移动后面部分
    for (int i = numsSize - k; i < numsSize; i++) {
        arr[ai] = nums[i];
        ai++;
    }
    // 移动前面部分
    for (int i = 0; i < numsSize - k; i++) {
        arr[ai] = nums[i];
        ai++;
    }

    // 粘贴回
    for (int i = 0; i < numsSize; i++) {
        nums[i] = arr[i];
    }
}

// 1 2 3
// 1 2 3 4
void reverse(int *arr, int size)
{
    int tmp = 0;
    for (int i = 0; i < (size >> 1); i++) {
        tmp = arr[size - i - 1];
        arr[size - i - 1] = arr[i];
        arr[i] = tmp;
    }
}

void rotate2(int* nums, int numsSize, int k)
{
    k = k % numsSize;
    reverse(nums, numsSize);
    reverse(&nums[k], numsSize - k);
    reverse(nums, k);
}

void debug_info(int *n, int size)
{
    for (int i = 0; i<size; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
int main()
{
    // printf("%d\n", gcd(6, 4));
    // printf("%d\n", gcd(4, 6));
    // printf("%d\n", gcd(9, 6));
    // printf("%d\n", gcd(3, 6));

    // 示例 1:
    // 输入: nums = [1,2,3,4,5,6,7], k = 3
    // 输出: [5,6,7,1,2,3,4]
    // 解释:
    // 向右轮转 1 步: [7,1,2,3,4,5,6]
    // 向右轮转 2 步: [6,7,1,2,3,4,5]
    // 向右轮转 3 步: [5,6,7,1,2,3,4]
    int n1[] = {1,2,3,4,5,6,7};
    rotate(n1, ARRAY_SIZE(n1), 3);
    // rotate1(n1, ARRAY_SIZE(n1), 3);
    // rotate2(n1, ARRAY_SIZE(n1), 3);
    debug_info(n1, ARRAY_SIZE(n1));

    // 示例 2:
    // 输入：nums = [-1,-100,3,99], k = 2
    // 输出：[3,99,-1,-100]
    // 解释: 
    // 向右轮转 1 步: [99,-1,-100,3]
    // 向右轮转 2 步: [3,99,-1,-100]
    int n2[] = {-1,-100,3,99};
    rotate(n2, ARRAY_SIZE(n2), 2);
    // rotate1(n2, ARRAY_SIZE(n2), 2);
    // rotate2(n2, ARRAY_SIZE(n2), 2);
    debug_info(n2, ARRAY_SIZE(n2));
}