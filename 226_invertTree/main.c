#include "../common.h"

#include "stdlib.h"
#include "stdbool.h"
 
struct TreeNode {
    int val; 
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL) {
        return NULL;
    }

    void *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}