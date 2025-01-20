#include <stdio.h>
#include <stdint.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    // Case1：需要处理总数为0，无需处理
    if (m + n == 0) {
        return;
    }

    // Case2：n的数量为0,无需处理
    if (n == 0) {
        return;
    }

    int index1 = m - 1;
    int index2 = n - 1;

    // Case3: 比较nums1和nums2的成员
    // 如果nums1成员耗尽，直接拷贝nums2的剩余成员到nums1
    // 如果nums2成员耗尽，则无需处理
    int i = m + n - 1;
    for(;i >= 0 && index1 >= 0 && index2 >= 0; i--) {
        if (nums1[index1] > nums2[index2]) {
            nums1[i] = nums1[index1];
            index1--;
        } else {
            nums1[i] = nums2[index2];
            index2--;
        }
    }

    while (index2 >= 0 && i >= 0) {
        nums1[i] = nums2[index2];
        i--;
        index2--;
    }
}

void debug_log(int* nums1, int nums1Size)
{
    if (nums1 == NULL || nums1Size == 0) {
        return;
    }
    for (int i = 0; i < nums1Size; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");
}

int main()
{

    // 示例 1：
    // 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    // 输出：[1,2,2,3,5,6]
    // 解释：需要合并 [1,2,3] 和 [2,5,6] 。
    // 合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
    int nums1[] = {1,2,3,0,0,0};
    int m = 3;
    int nums2[] = {2,5,6};
    int n = 3;
    merge(nums1, ARRAY_SIZE(nums1), m, nums2, ARRAY_SIZE(nums2), n);
    
    debug_log(nums1, ARRAY_SIZE(nums1));


    // 示例 2：
    // 输入：nums1 = [1], m = 1, nums2 = [], n = 0
    // 输出：[1]
    // 解释：需要合并 [1] 和 [] 。
    // 合并结果是 [1] 。

    int nums3[] = {1};
    m = 1;
    int nums4[] = {};
    n = 0;
    merge(nums3, ARRAY_SIZE(nums3), m, nums4, ARRAY_SIZE(nums4), n);
    debug_log(nums3, ARRAY_SIZE(nums3));

    // 示例 3：
    // 输入：nums1 = [0], m = 0, nums2 = [1], n = 1
    // 输出：[1]
    // 解释：需要合并的数组是 [] 和 [1] 。
    // 合并结果是 [1] 。
    // 注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。

    int nums5[] = {0};
    m = 0;
    int nums6[] = {1};
    n = 1;
    merge(nums5, ARRAY_SIZE(nums5), m, nums6, ARRAY_SIZE(nums6), n);
    debug_log(nums5, ARRAY_SIZE(nums5));
}