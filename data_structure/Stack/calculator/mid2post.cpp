#include "decl.h"
#include <iostream>
#include <assert.h>

using namespace std;

void Mid2Post::cout_top() {
    cout << "stack top is " << this->stack_operator.top() << endl;
}

Mid2Post::Mid2Post(std::string t_string) {
    this->target_string = t_string;
    std::cout << "You have just typed in a mid-expression which is \"" << t_string << "\"!" << std::endl;
}

Mid2Post::~Mid2Post() {
    // std::cout << "The result post-expression is \"" << this->res_string << "\"!" << std::endl;
}

int Mid2Post::get_priority(char ch) {
    if(ch == '(') return -1;
    if(ch == '+' || ch == '-') return 0;
    else if(ch == '*' || ch == '/')  return 1;
    else if(ch == '^') return 2;
}

void Mid2Post::deal_current_ch(char current_ch) {
    if(current_ch == '(') {
        this->stack_operator.push(current_ch);
        this->stack_top_priority = this->get_priority(current_ch);
    }
    else if(current_ch == ')') {
        while(this->stack_operator.top() != '(') {
            if(stack_operator.empty()) {
                throw std::runtime_error("Brackets does not match!");
            }
            this->res_string += this->stack_operator.top();
            this->stack_operator.pop();
        }
        assert(this->stack_operator.top() == '(');
        this->stack_operator.pop();
    }
    else if((int) current_ch - 48 >= 0 && (int) current_ch - 48 <= 9) {
        this->res_string += current_ch;
    }
    else{
        int current_priority = this->get_priority(current_ch);
        if(this->stack_operator.empty()) {
            this->stack_operator.push(current_ch);
            this->stack_top_priority = this->get_priority(current_ch);
        }
        else {
            while(this->stack_top_priority >= current_priority && !(this->stack_operator.empty())){
                this->res_string += this->stack_operator.top();
                this->stack_operator.pop();
                if(!this->stack_operator.empty()) this->stack_top_priority = get_priority(this->stack_operator.top());
                else this->stack_top_priority = -1;
            }
            this->stack_operator.push(current_ch);
            this->stack_top_priority = this->get_priority(current_ch);
        }
    }
    return;
}

void Mid2Post::transformer() {
    if(!this->target_string.size()) return;
    for(auto it = this->target_string.begin(); it != this->target_string.end(); it ++) {
        this->deal_current_ch(*it);
    }
    while(!this->stack_operator.empty()) {
        this->res_string += this->stack_operator.top();
        this->stack_operator.pop();
    }
}