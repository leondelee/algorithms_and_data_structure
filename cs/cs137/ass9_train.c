//
// Created by llw on 18-12-15.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 100
#define debug_assert assert(1 == 2)

typedef char element_type;
typedef struct Stack* s_ptr;
struct Stack {
    char* stack;
    int top;
    int max_size;
};

void init(s_ptr, int size);
void push(s_ptr S, element_type element);
element_type pop(s_ptr S);
void clean(s_ptr S);
int is_empty(s_ptr S);
element_type top(s_ptr S);
int is_valid(char* candidate, int size);

int main() {
    int num_coaches;
    while(1) {
        scanf("%d", & num_coaches);
        if(! num_coaches) break;
        getchar();
        int current_dg;
        char current_ch;
        char* candidate = (char *) malloc(sizeof(char) * num_coaches);
        int coach_cnt = 0;
        int break_flag = 0;
        while(! break_flag) {
            for(int j = 0; j < num_coaches; j ++) {
                scanf("%d", & current_dg);
                if(current_dg == 0) {
                    printf("\n");
                    break_flag = 1;
                    break;
                }
                candidate[j] = (char) current_dg + 48;
            }
            if(break_flag) break;
            int valid = is_valid(candidate, num_coaches);
            if(valid) printf("Yes\n");
            else printf("No\n");
            getchar();
        }
        free(candidate);
    }
    return 0;
}

void init(s_ptr S, int size) {
    S -> max_size = size;
    S -> stack = (char *) malloc(sizeof(char) * size);
    S -> top = -1;
}

void push(s_ptr S, element_type element) {
    if(S -> top >= S -> max_size - 1) return;
    S -> top ++;
    S -> stack[S -> top] = element;
}

element_type pop(s_ptr S) {
    if(S -> top == -1) return 'N';
    element_type res = S -> stack[S -> top];
    S -> top --;
    return res;
}

void clean(s_ptr S) {
    S -> top = -1;
}

int is_empty(s_ptr S) {
    return S -> top == -1;
}

element_type top(s_ptr S) {
    if(is_empty(S)) return 'E';
    assert(S -> top >= 0);
    return S -> stack[S -> top];
}

int is_valid(char* candidate, int size) {
    if(size == 1) return 1;
    s_ptr station = (s_ptr) malloc(sizeof(struct Stack));
    init(station, size);
    int coach_idx = 1;
    int used_cnt = 1;
    while(used_cnt <= size) {
        if(candidate[coach_idx - 1] != top(station)) {
            push(station, (char) used_cnt + 48);
            used_cnt ++;
        }
        else {
            pop(station);
            coach_idx ++;
        }
    }
    while(! is_empty(station)) {
        if(pop(station) != candidate[coach_idx - 1]) return 0;
        coach_idx ++;
    }
    clean(station);
    return 1;
}
