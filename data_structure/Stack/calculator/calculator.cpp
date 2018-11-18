#include <iostream>
#include <assert.h>
#include "decl.h"

using namespace std;

Calculator::Calculator(std::string obj_str) {
    this->target_exp = obj_str;
    std::cout << "Calculating the value of expression \"" << obj_str << "\"..."<< std::endl;
}

Calculator::~Calculator() {
    std::cout << "Result is " << this->res << std::endl;
}

void Calculator::calculate() {
    for(auto it = this->target_exp.begin(); it != this->target_exp.end(); it ++) {
        if((int) *it - 48 >= 0 && (int) *it - 48 <= 9) {
            this->ch_stack.push(*it);
        }
        else {
            this->current_operator = *it;
            this->calculate_one_step();
        }
    }
}

void Calculator::calculate_one_step() {
    assert(this->ch_stack.size() >= 1);
    int second_d = (int) this->ch_stack.top() - 48;
    this->ch_stack.pop();
    int first_d = (int) this->ch_stack.top() - 48;
    this->ch_stack.pop();
    switch (this->current_operator) {
        case '+':
            this->res = first_d + second_d;
            break;
        case '-':
            this->res = first_d - second_d;
            break;
        case '*':
            this->res = first_d * second_d;
            break;
        case '/':
            this->res = first_d / second_d;
            break;
    }
    this->ch_stack.push((char) this->res + 48);
    return;
}