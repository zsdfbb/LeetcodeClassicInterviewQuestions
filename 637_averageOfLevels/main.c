#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    double *al = calloc(10000, sizeof(double));

    struct TreeNode **list = calloc(10000, sizeof(void *));
    int level = 0;
    int start = 0, end = 1;
    list[0] = root;

    while (start < end) {
        int new_end = end;
        double sum = 0;
        for (int i = start; i < end; i++) {
            // 求和，处理当前层的平均值
            sum = sum + list[i]->val;

            // 填充下一层的节点
            if (list[i]->left) {
                list[new_end] = list[i]->left;
                new_end++;
            }
            if (list[i]->right) {
                list[new_end] = list[i]->right;
                new_end++;
            }
        }
        // 求当前层平均
        al[level] = sum / ((double)end - start);

        // 进入下一层
        start = end;
        end = new_end;
        level++;
    }

    *returnSize = level;
    return al;
}