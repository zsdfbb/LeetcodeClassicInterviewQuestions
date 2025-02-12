#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void swap(int *a, int *b)
{
    int t = *b;
    *b = *a;
    *a = t;
}

void debug_info(int *n, int size)
{
    for (int i = 0; i<size; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
}

#endif