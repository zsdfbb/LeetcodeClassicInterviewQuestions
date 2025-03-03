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
    void *data;
    int data_size;
    int elem_size;
    int count;
} queue_t;

queue_t *queue_init(int elem_size, int data_size)
{
    queue_t *q = calloc(1, sizeof(queue_t));
    q->elem_size = elem_size;
    q->data = calloc(data_size, elem_size);
    q->data_size = data_size;
    q->count = 0;

    return q;
}

int queue_add(queue_t *q, void *elem)
{
    if (q->count >= q->data_size) {
        q->data = realloc(q->data, q->data_size * 2);
        q->data_size = q->data_size * 2;
    }
    void *base = q->data + (q->count * q->elem_size);
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
    queue_t *q_node = queue_init(sizeof(struct TreeNode*), 2);
    queue_add(q_node, root);
    queue_add(q_res, q_node);


    // 遍历 队列的队列
    for (int i = 0; i < queue_count(q_res); i++) {
        q_node = (queue_t *)queue_data(q_res) + i;

        // 遍历 TreeNode的队列
        if (queue_count(q_node) > 0) {
            // 下一层的 TreeNode的队列
            queue_t *q_new = queue_init(sizeof(struct TreeNode*), 2);
            struct TreeNode *node_arr = queue_data(q_node);
            for (int j = 0; j < queue_count(q_node); j++) {
                if (node_arr[j].left)
                    queue_add(q_new, node_arr[j].left);
                if (node_arr[j].right)
                    queue_add(q_new, node_arr[j].right);
            }
            queue_add(q_res, q_new);
        }
    }

    // 数据转换
    int **res = calloc(sizeof(int *), queue_count(q_res));
    *returnSize = queue_count(q_res);
    (*returnColumnSizes) = calloc(sizeof(int), queue_count(q_res));
    int *cols = (*returnColumnSizes);

    for (int i = 0; i < queue_count(q_res); i++) {
        int *nums = res[i]; 
        // 第 i 层, 取出所有val
        q_node = (queue_t *)queue_data(q_res) + i;
        int col = queue_count(q_node);
        nums = malloc(sizeof(int) * col);
        struct TreeNode *nodes = queue_data(q_node);
        for (int j = 0; j < col; j++) {
            nums[j] = nodes[j].val;
        }

        cols[i] = col;

        queue_free(q_node);
    }
    queue_free(q_res);

    return res;
}

// =============================
#include "../common.h"
#define INVALID_VAL 2000

struct TreeNode *build_nodes(int *d, int size)
{
    struct TreeNode *nodes = calloc(size + 1, sizeof(struct TreeNode));
    
    for (int i = 1; i < size + 1; i++) {
        nodes[i].val = d[i];
        if (i*2 < size + 1) {
            void *tmp = &nodes[i*2];
            if &nodes[i*2])
            nodes[i].left = ;
        }
            

        if (i*2 + 1 < size + 1)
            nodes[i].right = &nodes[i*2 + 1];
    }
    return nodes;
}

int main()
{
    int d1[] = {INVALID_VAL/*丢弃*/, 3,9,20,INVALID_VAL, INVALID_VAL,15,7};
    struct TreeNode *root1 = build_nodes(d1, ARRAY_SIZE(d1));
    int *cols_size = NULL;
    int res_size = 0;
    int **res = levelOrder(root1 + 1, &res_size, &cols_size);

    for (int i = 0; i < res_size; i++) {
        for (int j = 0; j < cols_size[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    free(root1);

    return 0;
}