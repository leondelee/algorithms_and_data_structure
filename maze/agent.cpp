//
// Created by llw on 18-10-29.
//
#include <iostream>
#include <assert.h>

#include "decl.h"
#include "queue.cpp"

using namespace std;

Agent::Agent() {
    // parameter initialisations
    this->maze = this->maze_for_draw = this->env.maze;
    this->maze_size = this->env.maze_size;
    // queue assignment
    this->state_queue.enqueue(this->env.entrance);
    this->exploited_blocks.push_back(this->env.entrance);
    // maze output
    cout << "Target maze is: " << endl;
    this->output_maze(this->env.maze);
}

bool Agent::exploit(State current_state) {
    int current_distance = current_state.distance;
    int current_column = current_state.column;
    int current_row = current_state.row;
    if(current_column == this->env.exit.column && current_row == this->env.exit.row) return true;
    int next_column = current_column + 1;
    int next_row = current_row + 1;
    int last_column = current_column - 1;
    int last_row = current_row - 1;
    // exploited
    this->exploited_blocks.push_back(current_state);
    State candidate;
    candidate.distance = current_distance + 1;
    // whether at left boundary
    if(current_column != 0) {
        if(this->env.maze[current_row][last_column] == '#' && !this->whether_exploited(last_column, current_row)) {
            candidate.column = last_column;
            candidate.row = current_row;
            this->state_queue.enqueue(candidate);
        }
    }
    if(current_column != this->maze_size - 1) {
        if(this->env.maze[current_row][next_column] == '#' && !this->whether_exploited(next_column, current_row)) {
            candidate.column = next_column;
            candidate.row = current_row;
            this->state_queue.enqueue(candidate);
        }
    }
    if(current_row != 0) {
        if(this->env.maze[last_row][current_column] == '#' && !this->whether_exploited(current_column, last_row)) {
            candidate.column = current_column;
            candidate.row = last_row;
            this->state_queue.enqueue(candidate);
        }
    }
    if(current_row != this->maze_size - 1) {
        if(this->env.maze[next_row][current_column] == '#' && !this->whether_exploited(current_column, next_row)) {
            candidate.column = current_column;
            candidate.row = next_row;
            this->state_queue.enqueue(candidate);
        }
    }
    return false;
}

bool Agent::whether_exploited(int column, int row) {
    // judge whether exploited
    for(vector<State>::iterator ptr = this->exploited_blocks.begin(); ptr != this->exploited_blocks.end(); ptr ++) {
        if(column == ptr->column && row == ptr->row) return true;
    }
    return false;
}

void Agent::output_maze(char** maze) {
    for(int i = 0; i < this->maze_size; i ++) {
        cout << "[";
        for(int j = 0; j < this->maze_size; j ++) {
            cout << maze[i][j];
            if(j != this->maze_size - 1) cout << " ";
        }
        cout << "]" << endl;
    }
    cout << "Entrance position is (column = " << this->env.entrance.column << ", row = " << this->env.entrance.row << ")." << endl;
    cout << "Exit position is (column = " << this->env.exit.column << ", row = " << this->env.exit.row << ")." << endl;
}

void Agent::draw_path() {
    cout << "Drawing path..." << endl;
    int queue_length = this->state_queue.get_queue_length();
    assert(queue_length >= 1);
    for(int i = this->state_queue.front; i != this->state_queue.rear; i = (i + 1) % this->state_queue.max_size) {
        int row = this->state_queue.list_array[i].row;
        int column = this->state_queue.list_array[i].column;
        this->maze_for_draw[row][column] = state_queue.list_array[i].distance + 48;
    }
    this->output_maze(this->maze_for_draw);
}

int Agent::get_min_steps() {
    bool reach_exit = false;
    State last_state;
    while(this->state_queue.get_queue_length()) {
        this->draw_path();
        last_state = this->state_queue.dequeue();
        reach_exit = this->exploit(last_state);
        if(reach_exit) break;
    }
    return last_state.distance;
}