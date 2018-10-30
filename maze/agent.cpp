//
// Created by llw on 18-10-29.
//
#include <iostream>
#include <assert.h>

#include "decl.h"
#include "queue.cpp"

using namespace std;

Agent::Agent(Env env) {
    this->env = &env;
    this->maze = this->env->maze;
    this->maze_size = this->env->maze_size;
    Queue<State> state_queue(1000);
    this->state_queue = & state_queue;
    cout << "Target maze is: " << endl;
    this->output_maze(this->env->maze);
}

void Agent::exploit(State current_state) {
    int current_distance = current_state.distance;
    int current_column = current_state.column;
    int current_row = current_state.row;
    int next_column = current_column + 1;
    int next_row = current_row + 1;
    int last_column = current_column - 1;
    int last_row = current_row - 1;
    State candidate;
    candidate.distance = current_distance + 1;
    // whether at left boundary
    if(current_column != 0) {
        if(this->env->maze[current_row][last_column] == '0') {
            candidate.column = last_column;
            candidate.row = current_row;
            this->state_queue->enqueue(candidate);
        }
    }
    if(current_column != this->maze_size - 1) {
        if(this->env->maze[current_row][next_column] == '0') {
            candidate.column = next_column;
            candidate.row = current_row;
            this->state_queue->enqueue(candidate);
        }
    }
    if(current_row != 0) {
        if(this->env->maze[last_row][current_column] == '0') {
            candidate.column = current_column;
            candidate.row = last_row;
            this->state_queue->enqueue(candidate);
        }
    }
    if(current_row != this->maze_size - 1) {
        if(this->env->maze[next_row][current_column] == '0') {
            candidate.column = current_column;
            candidate.row = next_row;
            this->state_queue->enqueue(candidate);
        }
    }
}

void Agent::output_maze(char** maze) {
    for(int i = 0; i < this->maze_size; i ++) {
        for(int j = 0; j < this->maze_size; j ++) {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "Entrance position is (" << this->env->entrance.column << ", " << this->env->entrance.row << ")." << endl;
    cout << "Exit position is (" << this->env->exit.column << ", " << this->env->exit.row << ")." << endl;
}

void Agent::draw_path() {
    char** tmp_maze;
    for(int i = 0; i < this->maze_size; i++) {
        for(int j = 0; j < this->maze_size; j ++) {
            tmp_maze[i][j] = this->maze[i][j];
        }
    }
    int queue_length = this->state_queue->get_queue_length();
    assert(queue_length >= 1);
    for(int i = 0; i < this->state_queue->get_queue_length(); i ++) {
        int row = this->state_queue->list_array[i].row;
        int column = this->state_queue->list_array[i].column;
        tmp_maze[row][column] = state_queue->list_array[i].distance;
    }
    this->output_maze(tmp_maze);
}