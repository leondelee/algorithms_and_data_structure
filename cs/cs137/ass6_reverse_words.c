//
// Created by llw on 18-10-31.
//
#include <stdio.h>
#include <assert.h>

void reverse_word(char* word, int word_length);
void deal_line();

int main() {
    int num_of_test_case = 0;
    scanf("%d", &num_of_test_case);
    getchar();
    for(int ntc = 0; ntc < num_of_test_case; ntc ++) {
        deal_line();
    }
    return 0;
}

void reverse_word(char* word, int word_length) {
    assert(word_length >= 1);
    for(int i = 0; i < word_length; i++) {
        printf("%c", word[word_length - i - 1]);
    }
}

void deal_line() {
    int word_length = 0;
    char current_ch;
    char current_word[1000];
    while(scanf("%c", &current_ch)) {
        if(current_ch == ' ') {
            reverse_word(current_word, word_length);
            printf(" ");
            word_length = 0;
        }
        else if(current_ch == '\n') {
            reverse_word(current_word, word_length);
            printf("\n");
            break;
        }
        else {
            current_word[word_length] = current_ch;
            word_length ++;
        }
    }
}


