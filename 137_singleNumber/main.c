#include "../common.h"
#include <stdio.h>

int singleNumber(int* nums, int numsSize)
{
    unsigned int res = 0;

    for (int i = 0; i < 32; i++) {
        unsigned int bit = 0;
        for (int j = 0; j < numsSize; j++) {
            unsigned int nj = (unsigned int)nums[j];
            bit = bit + ((nj >> i) & 1);
        }
        bit = bit % 3;
        
        res = res | (bit << i);
    }

    return res;
}

int main()
{
    // 示例 1：
    // 输入：nums = [2,2,3,2]
    // 输出：3
    int n1[] = {2,2,3,2};
    printf("%d\n", singleNumber(n1, ARRAY_SIZE(n1)));

    // 示例 2：
    // 输入：nums = [0,1,0,1,0,1,99]
    // 输出：99
    int n2[] = {0,1,0,1,0,1,99};
    printf("%d\n", singleNumber(n2, ARRAY_SIZE(n2)));

    return 0;
}
