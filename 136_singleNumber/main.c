#include "../common.h"

int singleNumber(int* nums, int numsSize)
{
        unsigned int res = 0;
        for (int i = 0; i < numsSize; i++) {
            res ^= (unsigned int)nums[i];
        }
        return (int)res;
}

int main()
{
    // 示例 1 ：
    // 输入：nums = [2,2,1]
    // 输出：1
    int n1[] = {2,2,1};
    printf("%d\n", singleNumber(n1, ARRAY_SIZE(n1)));
    
    // 示例 2 ：
    // 输入：nums = [4,1,2,1,2]
    // 输出：4
    int n2[] = {4,1,2,1,2};
    printf("%d\n", singleNumber(n2, ARRAY_SIZE(n2)));
    
    // 示例 3 ：
    // 输入：nums = [1]
    // 输出：1
    int n3[] = {1};
    printf("%d\n", singleNumber(n3, ARRAY_SIZE(n3)));

    return 0;
}