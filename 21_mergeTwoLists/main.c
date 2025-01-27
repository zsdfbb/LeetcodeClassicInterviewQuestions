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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *nn = NULL;
    struct ListNode *n1 = list1;
    struct ListNode *n2 = list2;

    while (n1 != NULL && n2 != NULL) {
        if (n1->val > n2->val) {
            
        }
        struct ListNode *nmax = ( ? )
        if (nn == NULL) {}
    }
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