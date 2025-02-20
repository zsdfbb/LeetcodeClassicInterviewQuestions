#include "stdio.h"
#include "stdlib.h"
#include "../common.h"
#include <stdio.h>

typedef struct {
    long long *stack;
    int top;
    long long min_val;
} MinStack;


MinStack* minStackCreate() {
    MinStack *ms = malloc(sizeof(MinStack));
    ms->stack = malloc(3*10000 * sizeof(long long));
    ms->top = 0;
    ms->min_val = 0;

    return ms;
}

void minStackShow(MinStack *obj) {
    for (int i = 0; i < obj->top; i++) {
        printf("%lld ", obj->stack[i]);
    }
    printf("\n");
    printf("min_val:%lld\n", obj->min_val);
    printf("\n");
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top != 0) {
        long long diff = val - obj->min_val;
        obj->stack[obj->top] = diff;
        obj->top++;

        if (diff < 0) {
            obj->min_val = val;
        }
    } else {
        obj->min_val = val;
        obj->stack[obj->top] = 0;
        obj->top++;
    }

    //minStackShow(obj);
}

void minStackPop(MinStack* obj) {
    int i = obj->top - 1;
    if (obj->stack[i] < 0) {
        obj->min_val = obj->min_val - obj->stack[i];
    }
    obj->top = i;
    if (i == 0) {
        obj->min_val = 0;
    }

    //minStackShow(obj);
}

int minStackTop(MinStack* obj) {
    int i = obj->top - 1;
    if (obj->stack[i] >= 0) {
        return obj->stack[i] + obj->min_val;
    } else {
        return obj->min_val;
    }

    //minStackShow(obj);
}

int minStackGetMin(MinStack* obj)
{
    //minStackShow(obj);
    return obj->min_val;
}

void minStackFree(MinStack* obj)
{
    free(obj->stack);
    free(obj);
}



/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

/*
["MinStack","push","push","push","top","pop",
"getMin","pop","getMin","pop","push","top",
"getMin","push","top","getMin","pop","getMin"]

输入
[[],[2147483646],[2147483646],[2147483647],[],[]
,[],[],[],[],[2147483647],[],
[],[-2147483648],[],[],[],[]]

[null,null,null,null,2147483647,null,2147483646,
null,2147483646,null,null,2147483647,2147483647,
null,-2147483648,-2147483648,null,2147483647]
*/

int main()
{
    MinStack *ms = minStackCreate();
    minStackPush(ms, 2147483646);
    minStackPush(ms, 2147483646);
    minStackPush(ms, 2147483647);
    minStackTop(ms);
    minStackPop(ms);

    minStackGetMin(ms);
    minStackPop(ms);
    minStackGetMin(ms);
    minStackPop(ms);
    minStackPush(ms, 2147483647);
    minStackTop(ms);

    minStackGetMin(ms);
    minStackPush(ms, -2147483648);
    minStackTop(ms);
    minStackGetMin(ms);
    minStackPop(ms);
    minStackGetMin(ms);

    return 0;
}