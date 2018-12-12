
// Created by llw on 18-12-5.
//
<<<<<<< HEAD
// Created by llw on 18-12-5.
//
#include <stdio.h>
#include <math.h>

typedef double USING_TYPE;

void my_swap(USING_TYPE* x, USING_TYPE* y);
void print_pts(double **pts, int num_pts);
int settle_pivot(USING_TYPE* A, int start, int stop);
void quick_sort(USING_TYPE* A, int start, int stop);
void sort_array(USING_TYPE* array, int start, int stop, void (*sort_func)(USING_TYPE*, int, int), int index);

//
//double find_minimum(T *start, T *stop);

int main() {
    int num_pts;
    while(scanf("%d\n", & num_pts)) {
        if(! num_pts) break;
        double **pts = (double **) malloc(sizeof(double *) * num_pts);
        for(int i = 0; i < num_pts; i++) {
            pts[i] = (double *) malloc(sizeof(double) * 2);
            scanf("%lf %lf\n", pts[i], pts[i] + 1);
        }
        print_pts(pts, num_pts);
    }
}

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

void print_pts(double **pts, int num_pts) {
    for(int i = 0; i < num_pts; i ++) {
        printf("x=%lf, y=%lf\n", pts[i][0], pts[i][1]);
    }
    return;
}

void sort_array(USING_TYPE* array, int start, int stop, void (*sort_func)(USING_TYPE*, int, int), int index) {

}