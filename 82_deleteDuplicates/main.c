#include "../common.h"
#include "stdlib.h"
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void ln_show(struct ListNode *head);

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode res = {0, head};
    struct ListNode free = {0, NULL};
    struct ListNode *free_tail = &free;

    struct ListNode *pre = &res;
    struct ListNode *cur = pre->next;
    while (cur) {
        // printf("cur(%p): %d\n", cur, cur->val);

        // 寻找删除的区间
        struct ListNode *rm_l = cur;
        struct ListNode *rm_r = cur;
        while (rm_r->next && rm_r->next->val == rm_l->val) {
            rm_r = rm_r->next;
        }

        // 如果 rm_l 和 rm_r 一样，说明不需要删除
        if (rm_l != rm_r) {
            // pre, [cur, rm_r] : 需要删除 [cur, rm_r] 的节点
            cur = rm_r->next;
            pre->next=rm_r->next;

            // 删除记录
            free_tail->next = rm_l;
            rm_r->next = NULL;
            free_tail = rm_r;
        } else {
            pre = cur;
            cur = cur->next;
        }
    }

    //便利free释放
    // ln_show(free.next);

    return res.next;
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
    struct ListNode *h = head;
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    while (h != NULL) {
        printf("%p ", h);
        h = h->next;
    }
    printf("\n");
}

void test(int *n, int nsize)
{
        struct ListNode *res = NULL;
        struct ListNode *h1 = ln_build(n, nsize);
        ln_show(h1);
        res = deleteDuplicates(h1);
        ln_show(res);
}

int main()
{
    int n1[] = {1,2,3,3,4,4,5};
    test(n1, ARRAY_SIZE(n1));

    return 0;
}