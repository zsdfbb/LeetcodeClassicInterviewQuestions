#include "../common.h"
#include "stdlib.h"
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode res = {0};
    struct ListNode *s = &res;
    struct ListNode *a = l1;
    struct ListNode *b = l2;

    int carry = 0;
    while (a != NULL && b != NULL){
        s->next = calloc(1, sizeof(struct ListNode));
        s = s->next;

        s->val = (a->val + b->val + carry) % 10;
        carry = (a->val + b->val + carry> 9 ? 1 : 0);

        a = a->next;
        b = b->next;
    }

    while (a != NULL) {
        s->next = calloc(1, sizeof(struct ListNode));
        s = s->next;

        s->val = (a->val + carry) % 10;
        carry = (a->val + carry > 9 ? 1 : 0);

        a = a->next;
    }

    while (b != NULL) {
        s->next = calloc(1, sizeof(struct ListNode));
        s = s->next;

        s->val = (b->val + carry) % 10;
        carry = (b->val + carry > 9 ? 1 : 0);

        b = b->next;
    }

    // printf("carry: %d\n", carry);
    if (carry) {
        s->next = calloc(1, sizeof(struct ListNode));
        s = s->next;

        s->val = 1;
    }

    return res.next;
}

int main()
{
    struct ListNode l1[2] = {
        {3, NULL},
        {7,NULL},
    };
    l1[0].next = &l1[1];

    struct ListNode l2[2] = {
        {9, NULL},
        {2,NULL},
    };
    l2[0].next = &l2[1];

    struct ListNode *res = addTwoNumbers(l1, l2);
    struct ListNode *tmp = res;
    struct ListNode *pre = NULL;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        pre = tmp;
        tmp = tmp->next;

        free(pre);
    }

    return 0;
}