//
// Created by llw on 18-12-8.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node* node_ptr;
struct Node {
    int digit;
    node_ptr next;
};
typedef struct Node* link_list;

link_list init();
long long int get_length(link_list L);
void insert(link_list L, int candidate, int front);
link_list num_mul_list(int number, link_list L);
link_list list_sum(link_list first, link_list second, int difference);
link_list list_mul_list(link_list first, link_list second);
void iterate_list(link_list L);

int main() {
    int num_cases;
    scanf("%d\n", & num_cases);
    for(int i = 0; i < num_cases; i ++) {
        int new_line_count = 0;
        char current_ch;
        int current_digit;
        link_list first = init();
        link_list second = init();
        link_list res_list;
        while(scanf("%c", & current_ch) != EOF) {
            if(current_ch == '\n') {
                new_line_count ++;
                if(new_line_count == 2) break;
            }
            current_digit = (int) current_ch - 48;
            if(0 <= current_digit && current_digit <= 9) {
                if(! new_line_count) insert(first, current_digit, 1);
                else insert(second, current_digit, 1);
            }
        }
        res_list = list_mul_list(first, second);
        iterate_list(res_list);
        if(i != num_cases - 1) printf("\n");
        free(first);
        free(second);
        free(res_list);
    }
    return 0;
}


link_list init() {
    link_list res = (link_list) malloc(sizeof(struct Node));
    res->next = NULL;
    return res;
}

long long int get_length(link_list L) {
    long long int count = 0;
    node_ptr c_ptr = L;
    while(c_ptr -> next != NULL) {
        count ++;
        c_ptr = c_ptr -> next;
    }
    return count;
}

void insert(link_list L, int candidate, int front) {
    if(front) {
        node_ptr tmp_node = init();
        tmp_node->digit = candidate;
        tmp_node->next = L->next;
        L->next = tmp_node;
    }
    else {
        node_ptr tmp_node = init();
        tmp_node->digit = candidate;
        node_ptr rear = L;
        while(rear -> next != NULL) rear = rear ->next;
        rear -> next = tmp_node;
    }
    return;
}

link_list num_mul_list(int number, link_list L) {
    link_list res_linked_list = init();
    node_ptr current_ptr = L;
    int carry = 0;
    while(current_ptr -> next != NULL) {
        int candidate = number * (current_ptr -> next -> digit)  + carry;
        insert(res_linked_list, candidate % 10, 0);
        carry = candidate / 10;
        current_ptr = current_ptr -> next;
    }
    if(carry) insert(res_linked_list, carry, 0);
    return res_linked_list;
}

link_list list_sum(link_list first, link_list second, int difference) {
    int carry = 0;
    int tic_toc = 0;
    node_ptr above_ptr = first;
    node_ptr under_ptr = second;
    link_list res_list = init();
    while(above_ptr -> next != NULL || under_ptr -> next != NULL) {
        int candidate = carry;
        if(under_ptr -> next != NULL && tic_toc >= difference) {
            candidate += under_ptr -> next -> digit;
            under_ptr = under_ptr -> next;
        }
        if(above_ptr -> next != NULL) {
            candidate += above_ptr -> next -> digit;
            above_ptr = above_ptr -> next;
        }
        insert(res_list, candidate % 10, 0);
        carry = candidate / 10;
        tic_toc ++;
    }
    if(carry) insert(res_list, carry, 0);
    free(first);
    free(second);
    return res_list;
}

link_list list_mul_list(link_list first, link_list second) {
    node_ptr under_ptr = second;
    link_list last_list = init();
    link_list this_list;
    insert(last_list, 0, 1);
    long long int digits = 0;
    while(under_ptr -> next != NULL) {
        this_list = num_mul_list(under_ptr -> next -> digit, first);
        last_list = list_sum(last_list, this_list, digits);
        digits ++;
        under_ptr = under_ptr -> next;
    }
    return last_list;
}

void iterate_list(link_list L) {
    if(L -> next == NULL) return;
    iterate_list(L -> next);
    printf("%d", L -> next -> digit);
}