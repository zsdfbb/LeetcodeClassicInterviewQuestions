#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int ln = maxDepth(root->left);
    int rn = maxDepth(root->right);
    return MAX(ln, rn) + 1;
}