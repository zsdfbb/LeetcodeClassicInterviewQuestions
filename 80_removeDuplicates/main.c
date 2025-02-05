#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define UNUSED_VAL (-100000)
int removeDuplicates(int* nums, int numsSize)
{
    int cur_val = UNUSED_VAL;
    int cur_count = 0;
    for (int i = 0; i < numsSize; i++) {
        // 初始化记录
        if (nums[i] != cur_val) {
            cur_val = nums[i];
            cur_count = 1;
        } else {
            // 重复计数
            cur_count++;
            if (cur_count > 2) {
                nums[i] = UNUSED_VAL;
            }
        }
    }

    // 将有效数字前移
    int slow = 0;
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] == UNUSED_VAL)
            continue;

        nums[slow] =  nums[fast];
        slow++;
    }

    return slow;
}

int removeDuplicates1(int* nums, int numsSize)
{
    if (numsSize < 3) {
        return numsSize;
    }

    int slow = 2;
    int fast = 2;
    while (fast < numsSize) {
        if (nums[slow - 2] != nums[fast]) {
            // nums[fast] 更大
            nums[slow] = nums[fast];
            slow++;
        } // else 至少第3次重复

        fast++;
    }
    return slow;
}

void debug_info(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}


#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
int main()
{

    // 示例 1：
    // 输入：nums = [1,1,1,2,2,3]
    // 输出：5, nums = [1,1,2,2,3]
    // 解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
    int n1[] = {1,1,1,2,2,3};
    int ret = removeDuplicates(n1, ARRAY_SIZE(n1));
    printf("ret: %d\n", ret);
    debug_info(n1, ret);


    // 示例 2：
    // 输入：nums = [0,0,1,1,1,1,2,3,3]
    // 输出：7, nums = [0,0,1,1,2,3,3]
    // 解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。
    int n2[] = {0,0,1,1,1,1,2,3,3};
    ret = removeDuplicates(n2, ARRAY_SIZE(n2));
    printf("ret: %d\n", ret);
    debug_info(n2, ret);

    return 0;
}