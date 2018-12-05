//
// Created by speit on 18-11-21.
// Some sorting algorithms implemented in c
//

#ifndef DEVOIR_MY_SORT_H
#define DEVOIR_MY_SORT_H

#include <assert.h>
#include "debug_tools.h"

#define USING_TYPE int

void my_swap(USING_TYPE* x, USING_TYPE* y) {
    USING_TYPE temp = *x;
    *x = *y;
    *y = temp;
}

int settle_pivot(USING_TYPE* A, int start, int stop) {
    int pivot_index = (start + stop) / 2;
    USING_TYPE pivot = A [ pivot_index ];
    while (start < stop) {
        while (A [ start ] < pivot) start ++;
        while (A [ stop ] > pivot) stop --;
        if (start < stop) {
            my_swap(& A [ start ], & A [ stop ]);
        }
        if (A [ start ] == A [ stop ] && A [ stop ] == pivot) {
            stop --;
        }
    }
    return start;
}

void quick_sort(USING_TYPE* A, int start, int stop) {
    if (start >= stop) return;
    int pivot_index = settle_pivot(A, start, stop);
    quick_sort(A, start, pivot_index - 1);
    quick_sort(A, pivot_index + 1, stop);
    return;
}

#endif //DEVOIR_MY_SORT_H
