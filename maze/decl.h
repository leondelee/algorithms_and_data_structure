
// Created by llw on 18-10-20.
//
#ifndef DEVOIR_DECL_H
#define DEVOIR_DECL_H

#include <vector>

#define QUEUE_SIZE 1000

struct State {
    int row; // the row order
    int column; // the column order
    int distance;
};

template <typename T> class Queue {
public:
    int max_size;
    int front;
    int rear;
    T* list_array;
    Queue();
    void enqueue(const T &element);
    T dequeue();
    int get_queue_length();
    void output_queue();
};

class Env {
public:
    int maze_size;
    char** maze;
    State entrance, exit;
    Env();
};

class Agent {
private:
    int min_steps;
    int queue_size;
    int maze_size;
    char** maze;
    char** maze_for_draw;
    std::vector<State> exploited_blocks;
public:
    Env env;
    Queue<State> state_queue;
    Agent();
    bool exploit(State current_state);
    bool whether_exploited(int column, int row);
    int get_min_steps();
    void draw_path();
    void output_maze(char** maze);
};
#endif
