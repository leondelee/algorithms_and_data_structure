//
// Created by llw on 18-12-14.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef char element_type;

typedef struct STRUCTNODE* node_ptr;
typedef struct STRUCTNODE {
    element_type element;
    struct STRUCTNODE* next;
}node;

typedef struct LINKLIST
{
    node_ptr head;  // Point to list header
    node_ptr tail;  // Pointer to last
    node_ptr fence; // Last element on left
    long long int left_cnt;    // Size of left
    long long int right_cnt;     // Size of right
}* LList;

void init(LList listLink);
void reset(LList L);
void my_remove(LList L, long long int index);
void insert(node_ptr nptr, element_type element);
void print_list(LList L);
void my_free_node(node_ptr L);

int main() {
    int num_cases;
    scanf("%d\n", & num_cases);
    for(int i = 0; i < num_cases; i ++) {
        LList char_list = (LList) malloc(sizeof(struct LINKLIST));
        init(char_list);
        element_type current_ch;
        long long int index;
        while(scanf("%c", & current_ch)) {
            if(current_ch == ' ') {
                scanf("%lld", & index);
                reset(char_list);
                if(index == 0) print_list(char_list);
                else {
                    my_remove(char_list, index);
                    print_list(char_list);
                }
                if(i != num_cases - 1) getchar();
                printf("\n");
                break;
            }
            insert(char_list -> fence, current_ch);
            char_list -> fence = char_list -> fence ->next;
        }
        my_free_node(char_list -> head);
        free(char_list);
    }
}

void init(LList listLink) {
    node_ptr tmp = (node_ptr) malloc(sizeof(node));
    tmp -> next = NULL;
    listLink -> head = listLink -> tail = listLink -> fence = tmp;
    listLink -> left_cnt = listLink -> right_cnt = 0;
}

void reset(LList L) {
    L -> fence = L -> head;
    node_ptr tmp = L -> fence;
    long long int cnt = 0;
    while(tmp -> next != NULL) {
        cnt ++;
        tmp = tmp -> next;
    }
    L -> tail = tmp;
    L -> right_cnt = cnt;
    L -> left_cnt = 0;
}

void insert(node_ptr nptr, element_type element) {
    node_ptr tmp = (node_ptr) malloc(sizeof(node));
    tmp -> element = element;
    tmp -> next = nptr -> next;
    nptr -> next = tmp;
}

void my_remove(LList L, long long int index) {
    while(L -> right_cnt > index) {
        L -> fence = L -> fence -> next;
        L -> left_cnt ++;
        L -> right_cnt --;
    }
    node_ptr tmp = L -> fence -> next;
    L -> fence -> next = tmp -> next;
    free(tmp);
}

void print_list(LList L) {
    L -> fence = L -> head;
    while(L -> fence -> next != NULL) {
        printf("%c", L -> fence -> next -> element);
        L -> fence = L -> fence -> next;
    }
}

void my_free_node(node_ptr L) {
    if(L -> next == NULL) return;
    my_free_node(L -> next);
    free(L);
}

