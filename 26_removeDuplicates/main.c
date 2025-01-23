#include <stdio.h>
#include <memory.h>

int removeDuplicates(int* nums, int numsSize)
{
    int fast_i = 0;
    int slow_i = 0;
    for (fast_i = 1; fast_i < numsSize; fast_i++) {
        if (nums[fast_i] > nums[slow_i]) {
            slow_i++;
            nums[slow_i] = nums[fast_i];
        }
    }
    return slow_i + 1;
}

void debug_info(int *nums, int k)
{
    if (nums == NULL) {
        return;
    }

    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main()
{
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

    int k = 0;
    int nums0[] = {1};
    k = removeDuplicates(nums0, ARRAY_SIZE(nums0));
    debug_info(nums0, k);


    int nums1[] = {1, 1, 2};
    k = removeDuplicates(nums1, ARRAY_SIZE(nums1));
    debug_info(nums1, k);
    
    // 0,0,1,1,1,2,2,3,3,4
    int nums2[] = {0,0,1,1,1,2,2,3,3,4};
    k = removeDuplicates(nums2, ARRAY_SIZE(nums2));
    debug_info(nums2, k);
}
