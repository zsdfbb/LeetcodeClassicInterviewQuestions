#include <stdlib.h>
#include "stdio.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* root, int *nodes,int nodes_size, int *nodes_count)
{
    if (root == NULL || nodes == NULL || nodes_count == NULL || *nodes_count >= nodes_size) {
        return;
    }

    dfs(root->left, nodes, nodes_size, nodes_count);
    nodes[*nodes_count] = root->val;
    // printf("%d %d\n", *nodes_count, root->val);
    (*nodes_count) = (*nodes_count) + 1;
    dfs(root->right, nodes, nodes_size, nodes_count);
}

int getMinimumDifference(struct TreeNode* root)
{
    int *nodes = calloc(10000, sizeof(int));
    int nodes_count = 0;
    dfs(root, nodes, 10000, &nodes_count);

    int min = 1000000;
    int tmp = 0;
    for (int i = 0; i + 1 < nodes_count; i++) {
        tmp = nodes[i+1] - nodes[i];
        min = (min < tmp ? min : tmp);
    }

    return min;
}