#include "../common.h"
#include "stdbool.h"

bool bin_search(int *arr, int arr_size, int target)
{
    int left = 0;
    int right = arr_size -1;
    int mid = 0; 
    while (left <= right) {
        mid = (left + right) / 2;
        if (target == arr[mid]) {
            return true;
        }
        if (target < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid +1;
        }
    }

    return false;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][*matrixColSize - 1] >= target) {
            return bin_search(&matrix[i][0], *matrixColSize, target);
        }
    }
    return false;
}

int main()
{
    // 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    // 输出：true
    int r1[] = {1,3,5,7};
    int r2[] = {10,11,16,20};
    int r3[] = {23,30,34,60};
    int *m1[] = {r1,r2,r3 };
    int colsize = 4;
    printf("%d\n", searchMatrix(m1, 3, &colsize, 3));
}