#include "../common.h"
#include "stdlib.h"
#include <stdatomic.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    struct ListNode *lp_pre = NULL;
    struct ListNode *lp = NULL;
    struct ListNode *rp = NULL;
    struct ListNode *rp_next = NULL;

    if(head->next == NULL) {
        return head;
    }

    // 找个上面的值对应的位置
    struct ListNode empty = {0, head};
    int count = 0;
    struct ListNode *tmp = &empty;
    while (tmp->next != NULL) {
        if (count+1 == left) {
            lp_pre = tmp;
            lp = tmp->next;
        }

        if (count+1 == right) {
            rp = tmp->next;
            rp_next = rp->next;
        }

        count++;
        tmp = tmp->next;
    }

    // printf("lp_pre: %p lp: %p rp: %p rp_next: %p\n", lp_pre, lp, rp, rp_next);
    if (lp && rp) {
        // 将left到right之间逆序
        // tmp -> tmp_next -> tmp_next_next
        struct ListNode *pre = lp;
        struct ListNode *next = NULL;
        tmp = lp->next;
        while (tmp != rp_next) {
            // 准备
            next = tmp->next;
            // 修改方向
            tmp->next = pre;
            // 下一轮
            pre = tmp;
            tmp = next;
        }

        // 链接前面和后面part
        lp->next = rp_next;
        lp_pre->next = rp;
    }
    return empty.next;
}

struct ListNode *ln_build(int *n, int size)
{
    struct ListNode *ln = calloc(size, sizeof(struct ListNode));

    for (int i = 0; i < size; i++) {
        ln[i].val = n[i];
        if (i < size-1) {
            ln[i].next = &ln[i + 1];
        }
    }
    return ln;
}

void ln_show(struct ListNode *head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void test(int *n, int nsize, int left, int right)
{
        struct ListNode *res = NULL;
        struct ListNode *h1 = ln_build(n, nsize);
        ln_show(h1);
        res = reverseBetween(h1, left, right);
        ln_show(res);
}

int main()
{
    int n1[] = {1,2,3,4,5};
    test(n1, ARRAY_SIZE(n1), 2, 4);

    int n2[] = {3,5};
    test(n2, ARRAY_SIZE(n2), 1, 1);

    int n3[] = {3,5};
    test(n3, ARRAY_SIZE(n3), 1, 2);

    return 0;
}