//
// Created by speit on 18-10-27.
//
#include <iostream>
#include "queue.cpp"
#include "decl.h"

using namespace std;

int main() {
    Queue<int> queue(10);
    for(int i = 0; i < 10; i++) queue.enqueue(i);
    queue.output_queue();
}
