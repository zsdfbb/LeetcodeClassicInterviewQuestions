#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

bool hasPathSum(struct TreeNode* root, int targetSum)
{
    if (root == NULL) {
        return false;
    }

    bool res = false;
    if (root->left == NULL && root->right == NULL) {
        res = (targetSum == root->val);
    }
    
    res = res || hasPathSum(root->left, targetSum - root->val);
    res = res || hasPathSum(root->right, targetSum - root->val);

    return res;
}
