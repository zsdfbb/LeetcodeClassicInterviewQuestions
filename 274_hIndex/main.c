#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include "../common.h"

int cmp(const void *a, const void *b)
{
    int *n1 = (int *)a;
    int *n2 = (int *)b;

    return *n1 - *n2;
}

int hIndex(int* citations, int citationsSize)
{
    qsort(citations, citationsSize, sizeof(int), cmp);
    debug_info(citations,citationsSize);
    int h = 0;
    for (int i = 0; i < citationsSize; i++) {
        // 后续文章数
        int cn = citationsSize - i;
        // 后续文章的最小引用次数
        if (cn <= citations[i]) {
            // h值要求：后续每篇论文的引用次数都大于文章数
            h = (h > cn ? h: cn);
        }
    }
    return h;
}

int main()
{
    // 示例 1：
    // 输入：citations = [3,0,6,1,5]
    // 输出：3 
    // 解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
    //     由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3。
    int c1[] = {3,0,6,1,5};
    printf("%d\n", hIndex(c1, ARRAY_SIZE(c1)));

    // 示例 2：
    // 输入：citations = [1,3,1]
    // 输出：1
    int c2[] = {1,3,1};
    printf("%d\n", hIndex(c2, ARRAY_SIZE(c2)));

    return 0;
}