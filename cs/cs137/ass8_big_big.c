//
// Created by llw on 18-12-8.
//

#include <stdio.h>

typedef Node* node_ptr;
struct Node {
    int digit;
    node_ptr next;
};
typedef Node* link_list;

link_list init();
int get_length(link_list L);
void insert(link_list L, int candidate);
link_list num_mul_list(int number, link_list L);
link_list list_sum(link_list first, link_list second);
link_list list_mul_list(link_list first, link_list second);
void iterate_list(link_list L);

int main() {
    int num_cases = 0;
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
                if(new_line_count) break;
                new_line_count ++;
            }
            current_digit = (int) current_ch - 48;
            if(0 >= current_digit && current_digit <= 9) {
                if(! new_line_count) insert(first, current_digit);
                else insert(second, current_digit);
            }
        }
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

int get_length(link_list L) {
    int count = 0;
    node_ptr c_ptr = L;
    while(c_ptr -> next != NULL) {
        count ++;
        c_ptr = c_ptr -> next;
    }
    return count;
}

void insert(link_list L, int candidate) {
    node_ptr tmp_node = (node_ptr) malloc(sizeof(struct Node));
    tmp_node->digit = candidate;
    L->next = tmp_node;
    tmp_node->next = L->next;
}

link_list num_mul_list(int number, link_list L) {
    link_list res_linked_list = init();
    node_ptr current_ptr = L;
    int carry = 0;
    while(current_ptr != NULL) {
        insert(res_linked_list, (number * (current_ptr -> digit)) % 10 + carry);
        carry = (number * (current_ptr -> digit)) % 10;
        node_ptr = current_ptr -> next;
    }
    return res_linked_list;
}

link_list list_sum(link_list first, link_list second) {
    int first_longer_flag = get_length(first) > get_length(second) ? 1 : 0;
    link_list under = first_longer_flag == 1 ? second : first;
    link_list above = first_longer_flag == 0 ? second : first;
    link_list res_list = init();
    int carry = 0;
    node_ptr above_ptr = above;
    node_ptr under_ptr = under;
    while(above_ptr -> next != NULL) {
        if(under_ptr -> next == NULL) {
            insert(res_list, (above_ptr -> digit + carry) % 10);
            carry = (above_ptr -> digit + carry) / 10;
        }
        else {
            insert(res_list, (above_ptr -> digit + under_ptr -> digit + carry) % 10);
            carry = (above_ptr -> digit + under_ptr -> digit + carry) / 10;
            under_ptr = under_ptr -> next;
        }
        above_ptr = above_ptr -> next;
    }
}

link_list list_mul_list(link_list first, link_list second) {
    int first_longer_flag = get_length(first) > get_length(second) ? 1 : 0;
    link_list under = first_longer_flag == 1 ? second : first;
    link_list above = first_longer_flag == 0 ? second : first;
    node_ptr under_ptr = under;
    link_list last_list = init();
    while(under_ptr -> next != NULL) {
        insert(last_list, 0);
        link_list this_list = num_mul_list(under_ptr -> digit, above);
        last_list = list_sum(last_list, this_list);
    }
    return last_list;
}

void iterate_list(link_list L) {
    node_ptr current_ptr = L;
    while(current_ptr != NULL) {
        printf("%d", current_ptr -> digit);
        current_ptr = current_ptr -> next;
    }
}