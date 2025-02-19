#include "../common.h"
#include <stdio.h>

int helper(int *n, int left, int right)
{
    // 一个元素
    if (left >= right) {
        return left;
    }

    // 多个元素
    int l = left;
    int r = right;
    int m = (left + right) / 2;
    printf("left:%d right:%d mid:%d\n", left, right, m);

    int nm = n[m];
    // nm正常情况只会出现一次,所有使用它作为边界
    int nml = nm;
    int nmr = nm;
    if (m - 1 >= left) {
        nml = n[m-1];
    }
    if (m + 1 <= right) {
        nmr = n[m+1];
    }
    // 直接结束
    if (nm >= nml && nm >= nmr) {
        return m;
    }

    // 抛弃左边
    if (nm >= nml) {
        return helper(n, m+1, right);
    }

    // 兜底，抛弃右边 nm >= nmr || nm最小
    return helper(n, left, m);
}

int findPeakElement(int* nums, int numsSize)
{
    return helper(nums, 0, numsSize-1);
}

int main()
{
    // 输入：nums = [1,2,1,3,5,6,4]
    // 输出：1 或 5 
    // 解释：你的函数可以返回索引 1，其峰值元素为 2；
    //      或者返回索引 5， 其峰值元素为 6。
    int n1[] = {1,2,1,3,5,6,4};
    int i = findPeakElement(n1, ARRAY_SIZE(n1));
    printf("%d\n", n1[i]);

    int n2[] = {1,2};
    i = findPeakElement(n2, ARRAY_SIZE(n2));
    printf("%d\n", n1[i]);

    return 0;
}