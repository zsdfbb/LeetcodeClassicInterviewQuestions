#include<stdlib.h>
#include <stdio.h>
#include <memory.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
typedef struct queue {
    void **data;
    int data_size;
    int elem_size;
    int count;
} queue_t;

queue_t *queue_init(int elem_size, int data_size)
{
    queue_t *q = calloc(1, sizeof(queue_t));
    q->elem_size = elem_size;
    q->data = calloc(data_size, elem_size);
    // printf("q->data: %p\n", q->data);
    q->data_size = data_size;
    q->count = 0;

    return q;
}

int queue_add(queue_t *q, void *elem)
{
    if (q->count >= q->data_size) {
        q->data = realloc(q->data, q->data_size * q->elem_size * 2);
        q->data_size = q->data_size * 2;
    }
    void **base = q->data + q->count;
    // printf("queue_add elem %p\n", *(void **)elem);
    // printf("queue_add base: %p\n", base);
    memcpy(base, elem, q->elem_size);
    q->count++;

    return q->count - 1;
}

void *queue_data(queue_t *q) {
    return q->data;
}

int queue_count(queue_t *q) {
    return q->count;
}

void queue_free(queue_t *q) {
    free(q->data);
    free(q);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 
    queue_t *q_res = queue_init(sizeof(queue_t *), 16);
    // TreeNode的队列
    queue_t *q_node = queue_init(sizeof(struct TreeNode *), 2);

    // printf("root: %p\n", root);
    // printf("q_res %p\n", q_res);
    // printf("root_q_node %p\n", q_node);

    queue_add(q_node, &root);
    queue_add(q_res, &q_node);

    // 遍历 队列的队列
    // printf("debug1\n");
    for (int i = 0; i < queue_count(q_res); i++) {
        // printf("i: %d\n", i);
        q_node = *((queue_t **)queue_data(q_res) + i);
        // printf("q_node: %p\n", q_node);

        // 遍历 TreeNode的队列
        // printf("queue_count(q_node): %d\n", queue_count(q_node));
        if (queue_count(q_node) > 0) {
            // 下一层的 TreeNode的队列
            queue_t *q_new = queue_init(sizeof(struct TreeNode*), 2);
            // printf("q_new: %p\n", q_new);
            struct TreeNode **node_ptr_arr = queue_data(q_node);
            for (int j = 0; j < queue_count(q_node); j++) {
                // printf("j: %d node:%p val:%d\n", j, (void *)node_ptr_arr[j], node_ptr_arr[j]->val);
                if (node_ptr_arr[j]->left) {
                    queue_add(q_new, &(node_ptr_arr[j]->left));
                    // printf("node_ptr_arr[j]->left val:%d\n", node_ptr_arr[j]->left->val);
                }
                if (node_ptr_arr[j]->right) {
                    queue_add(q_new, &(node_ptr_arr[j]->right));
                    // printf("node_ptr_arr[j]->right val:%d\n", node_ptr_arr[j]->right->val);
                }
            }
            // printf("add q_new\n");
            if (queue_count(q_new) > 0) {
                queue_add(q_res, &q_new);
            } else {
                queue_free(q_new);
            }
        }
    }

    // printf("debug2\n");
    // 数据转换
    int **res = calloc(sizeof(int *), queue_count(q_res));
    *returnSize = queue_count(q_res);
    (*returnColumnSizes) = calloc(sizeof(int), queue_count(q_res));
    int *cols = (*returnColumnSizes);

    // printf("queue_count(q_res): %d\n", queue_count(q_res));

    for (int i = 0; i < queue_count(q_res); i++) {
        int *nums = NULL; 
        // 第 i 层, 取出所有val
        q_node = *((queue_t **)queue_data(q_res) + i);
        int col = queue_count(q_node);
        nums = malloc(sizeof(int) * col);
        struct TreeNode **nodes = queue_data(q_node);
        for (int j = 0; j < col; j++) {
            nums[j] = nodes[j]->val;
            // printf("%d ", nums[j]);
        }
        // printf("\n");

        cols[i] = col;

        res[i] = nums;

        queue_free(q_node);
    }
    queue_free(q_res);

    return res;
}

// =============================
#include "../common.h"
#define INVALID_VAL 2000

void debug_tree(struct TreeNode *root) {
    if (root == NULL) {
        // printf("null ");
        return;
    }
    // printf("%d ", root->val);

    debug_tree(root->left);
    debug_tree(root->right);
}

struct TreeNode *build_nodes(int *d, int size)
{
    struct TreeNode *nodes = calloc(size + 1, sizeof(struct TreeNode));
    
    for (int i = 1; i < size; i++) {
        // printf("i: %d\n", i);
        // printf("%d\n", d[i]);
        if (d[i] == INVALID_VAL)
            continue;

        nodes[i].val = d[i];
        void *tmp = NULL; 
        if (i*2 < size + 1) {
            tmp = &nodes[i*2];
            // printf("left: %d\n", d[i*2]);
            if (d[i*2] == INVALID_VAL)
                tmp = NULL;
            nodes[i].left = tmp;
        }

        if (i*2 + 1 < size + 1) {
            // printf("right: %d\n", d[i*2 + 1]);
            tmp = &nodes[i*2 + 1];
            if (d[i*2 + 1] == INVALID_VAL)
                tmp = NULL;
            nodes[i].right = tmp;
        }
    }

    // printf("debug_tree:\n");
    debug_tree(nodes + 1);
    // printf("\n");
    return nodes;
}


int main()
{
    int d1[] = {INVALID_VAL/*丢弃*/, 3,9,20,INVALID_VAL, INVALID_VAL,15,7};
    // printf("ARRAY_SIZE(d1): %ld\n", ARRAY_SIZE(d1));
    struct TreeNode *root1 = build_nodes(d1, ARRAY_SIZE(d1));
    int *cols_size = NULL;
    int res_size = 0;
    int **res = levelOrder(root1 + 1, &res_size, &cols_size);

    // printf("debug3:\n");
    // printf("res_size: %d\n", res_size);
    for (int i = 0; i < res_size; i++) {
        for (int j = 0; j < cols_size[i]; j++) {
            // printf("%d ", res[i][j]);
        }
        // printf("\n");
        free(res[i]);
    }
    free(res);
    free(cols_size);

    free(root1);

    return 0;
}