/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode *l1 = list1;
    struct ListNode *l2 = list2;

    struct ListNode head = {0};
    struct ListNode * tmp = &head;

    while (l1!= NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tmp->next = l1;
            l1 = l1->next;
        } else {
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }

    if (l1 != NULL) {
        tmp->next = l1;
    }

    if (l2 != NULL) {
        tmp->next = l2;
    }

    return head.next;
}

int main()
{

    // 示例 1：
    // 输入：l1 = [1,2,4], l2 = [1,3,4]
    // 输出：[1,1,2,3,4,4]

    // 示例 2：
    // 输入：l1 = [], l2 = []
    // 输出：[]

    // 示例 3：
    // 输入：l1 = [], l2 = [0]
    // 输出：[0]

    return 0;
}