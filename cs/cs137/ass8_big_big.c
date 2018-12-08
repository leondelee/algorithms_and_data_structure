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
void insert(link_list L, int candidate);
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
        link_list res_list = init();
        while(scanf("%c", & current_ch) != EOF) {
            if(current_ch == '\n') {
                new_line_count ++;
                if(new_line_count == 2) break;
            }
            current_digit = (int) current_ch - 48;
            if(0 <= current_digit && current_digit <= 9) {
                if(! new_line_count) insert(first, current_digit);
                else insert(second, current_digit);
            }
        }
        link_list test = init();
        res_list = list_mul_list(first, second);
        iterate_list(res_list);
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

void insert(link_list L, int candidate) {
    node_ptr tmp_node = init();
    tmp_node->digit = candidate;
    tmp_node->next = L->next;
    L->next = tmp_node;
}

link_list num_mul_list(int number, link_list L) {
    link_list res_linked_list = init();
    node_ptr current_ptr = L;
    int carry = 0;
    while(current_ptr -> next != NULL) {
        insert(res_linked_list, (number * (current_ptr -> next -> digit)  + carry) % 10);
        carry = (number * (current_ptr -> next -> digit) + carry) / 10;
        current_ptr = current_ptr -> next;
    }
    return res_linked_list;
}

link_list list_sum(link_list first, link_list second, int difference) {
    int first_longer_flag = get_length(first) > get_length(second) + difference ? 1 : 0;
    link_list under = first_longer_flag == 1 ? second : first;
    link_list above = first_longer_flag == 0 ? second : first;
    link_list res_list = init();
    int carry = 0;
    int tic_toc = 0;
    node_ptr above_ptr = above;
    node_ptr under_ptr = under;
    while(above_ptr -> next != NULL) {
        if(under_ptr -> next == NULL) {
            insert(res_list, (above_ptr -> next -> digit + carry) % 10);
            carry = (above_ptr -> next -> digit + carry) / 10;
        }
        else if(under_ptr -> next != NULL && tic_toc <= difference){
            insert(res_list, (above_ptr -> next -> digit + under_ptr -> next -> digit + carry) % 10);
            carry = (above_ptr -> next -> digit + under_ptr -> next -> digit + carry) / 10;
            under_ptr = under_ptr -> next;
        }
        tic_toc ++;
        above_ptr = above_ptr -> next;
    }
    return res_list;
}

link_list list_mul_list(link_list first, link_list second) {
    int first_longer_flag = get_length(first) > get_length(second) ? 1 : 0;
    link_list under = first_longer_flag == 1 ? second : first;
    link_list above = first_longer_flag == 0 ? second : first;
    node_ptr under_ptr = under;
    link_list last_list = init();
    insert(last_list, 0);
    long long int digits = 0;
    while(under_ptr -> next != NULL) {
        link_list this_list = num_mul_list(under_ptr -> next -> digit, above);
        last_list = list_sum(last_list, this_list, digits);
        iterate_list(last_list);
        digits ++;
        under_ptr = under_ptr -> next;
    }
    return last_list;
}

void iterate_list(link_list L) {
    node_ptr current_ptr = L;
    while(current_ptr -> next != NULL) {
        printf("%d", current_ptr -> next -> digit);
        current_ptr = current_ptr -> next;
    }
    printf("\n");
}