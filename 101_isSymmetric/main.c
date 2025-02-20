#include "../common.h"

#include "stdlib.h"
#include "stdbool.h"
#include <stdio.h>

struct TreeNode {
    int val; 
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL) {
        return true;
    }

    struct TreeNode* queue[2048] = {0};
    int ql = 0;
    int qr = 0;
    queue[qr++] = root;

    while (ql < qr) {
        //printf("left: %d right: %d\n", ql, qr);
        // 判断 && 消费
        // 0 1 2 3 -> 1
        // 0 1 2 -> 1
        int left = ql;
        int right = qr - 1;
        while (left < right) {
            if (queue[left] == NULL && queue[right] == NULL) {
                // ok
                left++;
                right--;
                continue;
            }
            if (queue[left] == NULL || queue[right] == NULL) {
                // false
                return false;
            }
            if (queue[left]->val != queue[right]->val) {
                // false
                return false;
            }
            // queue[left]->val == queue[right]->val
            left++;
            right--;
        }
        //printf("left: %d right: %d\n", left, right);

        // 添加
        int new_qr = qr;
        for (int i = ql; i < qr; i++) {
            if (queue[i] != NULL) {
                //printf("qr:%d i: %d\n", new_qr, i);
                queue[new_qr++] = queue[i]->left;
                queue[new_qr++] = queue[i]->right;
            }
        }
        ql = qr;
        qr = new_qr;
    }

    return true;
}

struct TreeNode *gen_tl(int *n, int size)
{
    struct TreeNode *tl = calloc(size, sizeof(struct TreeNode));
    for (int i = 0; i < size; i++) {
        tl[i].val = n[i];

        int li = (i + 1) * 2 - 1;
        if (li < size) {
            tl[i].left = &tl[li];
        }

        int ri = (i + 1) * 2;
        if (ri < size) {
            tl[i].right = &tl[ri];
        }
    }

    return tl;
}

int main()
{
    int n1[] = {1,2,2,3,4,4,3};
    struct TreeNode *r1 = gen_tl(n1, ARRAY_SIZE(n1));
    //printf("%d\n", isSymmetric(r1));
}