// Created by llw on 18-12-5.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define debug_assert assert(1 == 2);
#define Nan 10000000

typedef struct TwoParts* node;

struct TwoParts {
    int l_cnt;
    int r_cnt;
};

double distance(int* p1, int* p2) {
    return sqrt(
            (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])
    );
}

int equal(int x, int y) {
    return x == y;
}

void my_swap(int** p1, int** p2) {
    int* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int** pts, int start, int stop, int index) {
    int pivot = pts[(start + stop) / 2][index];
    int front = start;
    int tail = stop;
    while(front < tail) {
        while(pts[front][index] < pivot) front ++;
        while(pts[tail][index] > pivot) tail --;
        if(front < tail) my_swap(& pts[front], & pts[tail]);
        if(equal(pts[front][index], pts[tail][index]) && equal(pts[front][index], pivot)) tail --;
    }
    return front;
}

void quick_sort(int** pts, int start, int stop, int index) {
    if(start >= stop) return;
    int prt = partition(pts, start, stop, index);
    quick_sort(pts, start, prt - 1, index);
    quick_sort(pts, prt + 1, stop, index);
    return;
}

node divide(int** pts, int start, int stop, int index) {
    int middle_idx = (start + stop) / 2;
    int pivot_index = pts[middle_idx][index];
    int l_cnt = 0;
    int r_cnt = 0;
    for(int i = start; i < stop; i ++) {
        if(pts[i][index] <= pivot_index) l_cnt ++;
        else r_cnt ++;
    }
    node res_node = (node) malloc(sizeof(struct TwoParts));
    res_node -> l_cnt = l_cnt;
    res_node -> r_cnt = r_cnt;
    return res_node;
}

double find_min(int** pts, int start, int stop) {
    if(stop - start == 1) return distance(pts[start], pts[stop]);
    if(stop - start <= 0) return Nan;
    int mid_x = pts[(start + stop) / 2][0];
    node parts_node = divide(pts, start, stop, 0);
    int l_cnt = parts_node -> l_cnt;
    int r_cnt = parts_node -> r_cnt;
    double left_min = find_min(pts, start, start + l_cnt - 1);
    double right_min = find_min(pts, start + l_cnt - 1, stop);
    double min = left_min <= right_min ? left_min : right_min;
    // find central points
    int mid_cnt = 0;
    for(int i = start; i < stop; i ++) {
        if(abs(pts[i][0] - mid_x) < min) mid_cnt ++;
    }
    if(mid_cnt == 0) {
        return min;
    }
    int** central_points = (int **) malloc(sizeof(int*) * mid_cnt);
    assert(mid_cnt > 0);
    mid_cnt = 0;
    for(int i = start; i < stop; i ++) {
        if(abs(pts[i][0] - mid_x) < min) {
            central_points[mid_cnt] = (int *) malloc(sizeof(int) * 2);
            central_points[mid_cnt][0] = pts[i][0];
            central_points[mid_cnt][1] = pts[i][1];
            mid_cnt ++;
        }
    }
    quick_sort(central_points, 0, mid_cnt - 1, 1);
    for(int j = 0; j < mid_cnt; j ++) {
        for(int counted = 1; counted < 7; counted ++) {
            if(j + counted < mid_cnt) {
                min = min <= distance(central_points[j], central_points[j + counted]) ? min : distance(central_points[j], central_points[j + counted]);
            }
        }
    }
    free(central_points);
    return min;
}

int main() {
    int num_pts;
    while(1) {
        scanf("%d", & num_pts);
        if(! num_pts) break;
        int **pts = (int **) malloc(sizeof(int *) * num_pts);
        for(int i = 0; i < num_pts; i++) {
            pts[i] = (int *) malloc(sizeof(int) * 2);
            scanf("%d %d", pts[i], pts[i] + 1);
        }
        quick_sort(pts, 0, num_pts - 1, 0);
        double min = find_min(pts, 0, num_pts - 1);
        free(pts);
        printf("%.2lf\n", min);
    }
}

