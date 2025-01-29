#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    struct ListNode *fastp = head;
    struct ListNode *slowp = head;

    while (fastp != NULL && fastp->next != NULL) {
        fastp = fastp->next->next;
        slowp = slowp->next;
        if (fastp == slowp) {
            return true;
        }
    }
    return false;
}
