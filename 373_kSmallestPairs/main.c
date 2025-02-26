
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct pair {
    int n1i;
    int n2i;
    int sum;
};

struct min_heap {
    struct pair *pairs;
    int size;

    // 指向当前可以插入的位置，从1开始
    int count;
};

struct min_heap *min_heap_create(int size)
{
    struct min_heap *mheap = calloc(1, sizeof(*mheap));
    mheap->pairs = calloc(size+1, sizeof(struct pair));
    // 0要空着
    mheap->count = 1;
    mheap->size = size;

    return mheap;
}

void min_heap_free(struct min_heap *mheap)
{
    free(mheap->pairs);
    free(mheap);
}

int min_heap_insert(struct min_heap *mheap, struct pair np)
{
    int count = mheap->count;
    if (count >= mheap->size) {
        printf("min heap is full\n");
        return -1;
    }

    struct pair *pl = mheap->pairs;
    // 去重


    // 开始插入
    pl[count] = np;
    // 下移父亲节点
    int i = 0;
    for (int i = count; i > 0 && np.sum < pl[i/2].sum; i = i/2) {
        pl[i] = pl[i/2];
    }
    // 填充新节点
    pl[i] = np;
    mheap->count += 1;
}

struct pair *min_heap_pop(struct min_heap *mheap)
{
    int count = mheap->count;
    struct pair *pl = mheap->pairs;

    if (count <= 1) {
        return NULL;
    }

    if (count == 2) {
        return &pl[1];
    }

    struct pair tmp = pl[count -1];
    pl[count -1] = pl[1];
    pl[1] = tmp;

    int li = 1;
    int ri = 1;
    int mi = 1;
    for (int i = 1; i < count-1; i = mi) {
        mi = i;
        li = mi * 2;
        ri = li + 1;

        if (li < count - 1 && pl[mi].sum > pl[li].sum) {
            mi = li;
        }

        if (ri < count - 1 && pl[mi].sum > pl[ri].sum) {
            mi = ri;
        }

        if (mi != i) {
            tmp = pl[mi];
            pl[mi] = pl[i];
            pl[i] = pl[mi];
        } else {
            break;
        }
    }
    // 数量减少
    mheap->count--;

    return &(pl[count -1]);
}

int** kSmallestPairs(int* nums1, int nums1Size, 
                    int* nums2, int nums2Size, 
                    int k, 
                    int* returnSize, int** returnColumnSizes)
{
    int **arr = calloc(k, sizeof(int*));
    for (int i = 0; i < k; i++) {
        arr[i] = calloc(2, sizeof(int));
    }
    *returnSize = k;
    (*returnColumnSizes) = calloc(k, sizeof(int));
    int *col_size_arr = (*returnColumnSizes);
    for (int i = 0; i < k; i++) {
        col_size_arr[i] = 2;
    }

    // 准备最小堆, 从中选出topK的元素

    // 初始化


    return arr;
}

int main()
{
    int k = 0;
    int **res = NULL;
    int ret_size = 0;
    int *ret_col_size = 0;
    // 示例 1:
    // 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
    // 输出: [1,2],[1,4],[1,6]
    // 解释: 返回序列中的前 3 对数：
    //     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
    int n11[] = {1,7,11};
    int n22[] = {2,4,6};
    k = 3;
    res = kSmallestPairs(n11, ARRAY_SIZE(n11), n22, ARRAY_SIZE(n22), k, &ret_size, &ret_col_size);
    for (int i = 0; i < k; i++) {
        printf("[%d %d] ", res[i][0], res[i][1]);
    }
    printf("\n");

    // 示例 2:
    // 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
    // 输出: [1,1],[1,1]
    // 解释: 返回序列中的前 2 对数：
    //     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

    return 0;
}