// Created by llw on 18-12-5.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define debug_assert assert(1 == 2);
#define Nan 1000000

typedef struct TwoParts* node;

struct TwoParts {
    double*** parts;
    int l_cnt;
    int r_cnt;
};

double distance(double* p1, double* p2) {
    return sqrt(
            (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])
            );
}

int equal(double x, double y) {
    return x == y;
}

void my_swap(double** p1, double** p2) {
    double* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void print_pts(double** pts, int num_pts) {
    for(int i = 0; i < num_pts; i ++) {
        printf("x=%lf, y=%lf\n", pts[i][0], pts[i][1]);
    }
    return;
}

int partition(double** pts, int start, int stop, int index) {
    double pivot = pts[(start + stop) / 2][index];
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

void quick_sort(double** pts, int start, int stop, int index) {
    if(start >= stop) return;
    int prt = partition(pts, start, stop, index);
    quick_sort(pts, start, prt - 1, index);
    quick_sort(pts, prt + 1, stop, index);
    return;
}

node divide(double** pts, int start, int stop, int index) {
    double*** res = (double ***) malloc(sizeof(double **) * 2);
    int middle_idx = (start + stop) / 2;
    double pivot_index = pts[middle_idx][index];
    int l_cnt, r_cnt;
    for(int i = 0; i < stop - start; i ++) {
        if(pts[i][index] <= pivot_index) l_cnt ++;
        else r_cnt ++;
    }
    double** left_part = (double *) malloc(sizeof(double) * l_cnt);
    double** right_part = (double *) malloc(sizeof(double) * r_cnt);
    l_cnt = r_cnt = 0;
    for(int i = 0; i < stop - start; i ++) {
        if(pts[i][index] <= pivot_index) {
               left_part[l_cnt] = pts[i];
               l_cnt ++;
        }
        else {
            right_part[r_cnt] = pts[i];
            r_cnt ++;
        }
    }
    res[0] = left_part;
    res[1] = right_part;
    node res_node = (node) malloc(sizeof(struct TwoParts));
    res_node -> parts = res;
    res_node -> l_cnt = l_cnt;
    res_node -> r_cnt = r_cnt;
    return res_node;
}

double find_min(double** pts, int start, int stop) {
    if(stop - start == 1) return distance(pts[start], pts[stop]);
    if(stop - start <= 0) return Nan;
    double mid_x = pts[(start + stop) / 2][0];
    node parts_node = divide(pts, start, stop, 0);
    double** left_part = parts_node -> parts[0];
    double** right_part = parts_node -> parts[1];
    int l_cnt = parts_node -> l_cnt;
    int r_cnt = parts_node -> r_cnt;
    free(parts_node -> parts);
    free(parts_node);
    double left_min = find_min(left_part, 0, l_cnt - 1);
    double right_min = find_min(right_part, 0, r_cnt - 1);
    double min = left_min <= right_min ? left_min : right_min;
    // find central points
    int mid_cnt = 0;
    for(int i = 0; i < stop - start; i ++) {
        if(abs(pts[i][0] - mid_x) < min) mid_cnt ++;
    }
    if(mid_cnt == 0) return min;
    double** central_points = (double **) malloc(sizeof(double) * mid_cnt);
    assert(mid_cnt > 0);
    mid_cnt = 0;
    for(int i = 0; i < stop - start; i ++) {
        if(abs(pts[i][0] - mid_x) < min) {
            central_points[mid_cnt] = pts[i];
            mid_cnt ++;
        }
    }
    quick_sort(central_points, 0, mid_cnt - 1, 1);
    for(int j = 0; j < mid_cnt; j ++) {
        int counted = 1;
        if(j + counted < mid_cnt && counted < 7) {
            min = min <= distance(central_points[j], central_points[j + counted]) ? min : distance(central_points[j], central_points[j + counted]);
        }
    }
    return min;
}

int main() {
    int num_pts;
    while(1) {
        scanf("%d", & num_pts);
        if(! num_pts) break;
        double **pts = (double **) malloc(sizeof(double *) * num_pts);
        for(int i = 0; i < num_pts; i++) {
            pts[i] = (double *) malloc(sizeof(double) * 2);
            scanf("%lf %lf", pts[i], pts[i] + 1);
        }
        quick_sort(pts, 0, num_pts - 1, 0);
        double min = find_min(pts, 0, num_pts - 1);
        printf("%.2lf\n", min);
    }
}

