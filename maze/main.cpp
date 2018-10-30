//
// Created by speit on 18-10-27.
//
#include <iostream>
#include "decl.h"
#include "queue.cpp"

using namespace std;

int main() {
    Env maze;
    Queue<State> state_queue(100);
    Agent agent(maze, state_queue);
    agent.draw_path();

}
