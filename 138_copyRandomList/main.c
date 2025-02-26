
#include <stdio.h>
#include <stdlib.h>

#include "../common.h"

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node* head)
{
    struct Node new = {0};
    struct Node *arr = &new;

    // 统计个数， 所有新node一起申请出来
    int node_count = 0;
    for (struct Node *h = head; h; h = h->next) {
        node_count++;
    }
    arr->next = calloc(node_count, sizeof(new));
    arr = arr->next;

    int ai = 0;
    for (struct Node* h = head; h != NULL; h = h->next) {
        arr[ai].val = h->val;
        arr[ai].next = (ai < node_count - 1 ? (&(arr[ai + 1])) : NULL);

        if (h->random != NULL) {
            // 这里可以换成hash， 更快
            int ri = 0;
            for (struct Node *i = head; i; i = i->next) {
                if (i == h->random) {
                    break;
                }
                ri++;
            }
            printf("%d\n", ri);
            arr[ai].random = &(arr[ri]);
        }
        ai++;
    }

    return new.next;
}

void debug_node_list(struct Node *head)
{
    printf("debug_node_list:\n");
    for (struct Node *h = head; h; h=h->next) {
        printf("addr:%p val:%d next: %p random: %p\n", h, h->val, h->next, h->random);
    }
}

const int invalid_val = -100000;

void test(int (*hv1)[2], int hv_size)
{
    printf("hv: %p\n", hv1);

    int node_num = hv_size;
    struct Node *hn1 = calloc(node_num, sizeof(*hn1));
    for (int i = 0; i < hv_size; i++) {
        printf("hv[%d][%d]: %p\n", i, 0, &(hv1[i][0]));
        hn1[i].val = hv1[i][0];
        if (i+1 < hv_size) {
            hn1[i].next = &hn1[i+1];
        }
        if (hv1[i][1] != invalid_val) {
            hn1[i].random = &hn1[hv1[i][1]];
        }
    }

    debug_node_list(hn1);

    struct Node *res = copyRandomList(hn1);
    debug_node_list(res);
}

int main()
{
    int res = 0 ;
    // 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    // 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
    int hv1[][2] = {
        {7, invalid_val},
        {13,0},
        {11,4},
        {10,2},
        {1,0}
    };
    printf("hv1: %p\n", hv1);
    test(hv1, ARRAY_SIZE(hv1));

    return 0;
}