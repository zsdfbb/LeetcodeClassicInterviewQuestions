#include <stdio.h>
#include <stdlib.h>

int test(int **arr, int rows, int cols)
{
    int *tmp = (int *)arr;
    for (int i = 0; i < rows * cols; i++) {
        printf("%d ", tmp[i]);
    }
    return 0;
}

int main()
{
    int arr[2][2] = {{1,2}, {3,4}};
    test(arr, 2, 2);
    return 0;
}