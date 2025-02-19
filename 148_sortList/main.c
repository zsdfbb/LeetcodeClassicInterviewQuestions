/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include "../common.h"
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void debug_list(struct ListNode *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* sortList(struct ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }

    // 只有一个元素，类似 head->next == NULL
    if (head->next == NULL) {
        return head;
    }

    // 多个元素，先分开
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *pre = head;

    while (fast != NULL) {
        pre = slow;
        slow = slow->next;
        fast = (fast != NULL ? fast->next : NULL);
        fast = (fast != NULL ? fast->next : NULL);
    }
    pre->next = NULL;
    // debug_list(head);
    // debug_list(slow);

    // 分别排序
    struct ListNode nh = {0};
    struct ListNode *tmp = NULL;
    struct ListNode *h1 = sortList(head);
    struct ListNode *h2 = sortList(slow);

    // 合并
    tmp = &nh;
    while (h1 != NULL && h2 != NULL) {
        if (h1->val < h2->val) {
            tmp->next = h1;
            h1 = h1->next;
        } else {
            tmp->next = h2;
            h2 = h2->next;
        }
        tmp = tmp->next;
    }

    while (h1 != NULL) {
        tmp->next = h1;
        tmp = tmp->next;
        h1 = h1->next;
    }

    while (h2 != NULL) {
        tmp->next = h2;
        tmp = tmp->next;
        h2 = h2->next;
    } 

    // debug_list(nh);
    return nh.next;
}

int main()
{
    // 输入：head = [4,2,1,3]
    // 输出：[1,2,3,4]
    struct ListNode ln[] = {
        {4, NULL},
        {2, NULL},
        {1, NULL},
        {3, NULL},
    };
    ln[0].next = &ln[1];
    ln[1].next = &ln[2];
    ln[2].next = &ln[3];
    struct ListNode *res = sortList(ln);
    debug_list(res);

    return 0;
}