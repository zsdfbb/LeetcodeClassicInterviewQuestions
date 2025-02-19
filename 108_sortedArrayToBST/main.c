#include "stdlib.h"

#include "../common.h"
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void debug_tree_ldr(struct TreeNode* root)
{
    if (root == NULL) {
        printf("null ");
        return;
    }

    debug_tree_ldr(root->left);
    printf("%d ", root->val);
    debug_tree_ldr(root->right);
}


void debug_tree_dlr(struct TreeNode* root)
{
    if (root == NULL) {
        printf("null ");
        return;
    }

    printf("%d ", root->val);
    debug_tree_dlr(root->left);
    debug_tree_dlr(root->right);
}

struct TreeNode* helper(int* nums, int left, int right)
{
    if (left > right) {
        return NULL;
    }

    int mid = (left + right) / 2;
    // printf("left: %d  right: %d mid:%d\n", left, right, mid);

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = helper(nums, left, mid -1);
    root->right = helper(nums, mid + 1, right);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return helper(nums, 0, numsSize -1);
}

int main()
{
    int n1[] = {-10,-3,0,5,9};
    struct TreeNode *root = sortedArrayToBST(n1, ARRAY_SIZE(n1));
    debug_tree_ldr(root);
    printf("\n");
    debug_tree_dlr(root);
    printf("\n");

    return 0;
}