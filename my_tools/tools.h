//
// Created by speit on 18-11-14.
//

#ifndef DEVOIR_TOOLS_H
#define DEVOIR_TOOLS_H

#define my_for(i, start_index, end_index) for(int i = start_index; i < end_index; i++)

#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
void my_cout(T message) {
    cout << message << endl;
}

template <typename T>
void my_assert(T message) {
    assert(message);
}

bool ascending(int w1, int w2) {
    return w1 > w2;
}

#endif //DEVOIR_TOOLS_H
