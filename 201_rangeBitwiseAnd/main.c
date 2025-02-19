#include "../common.h"
#include <stdio.h>

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left = left >> 1;
        right = right >> 1;
        shift++;
    }
    return left << shift;
}

// 5: 0101
// 7: 0111
int main()
{
    printf("%d\n", rangeBitwiseAnd(5, 7));
    return 0;
}