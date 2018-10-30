//
// Created by speit on 18-10-27.
//
#include <iostream>
#include "decl.h"
//#include "queue.cpp"

using namespace std;

int main() {
    Env maze;
    Agent agent(maze);
    cout <<"&&&&&&&&&&&&&&&&&" << agent.state_queue->rear << endl;
    // agent.draw_path();
    cout <<"&&&&&&&&&&&&&&&&&" << agent.state_queue->rear << endl;
}
