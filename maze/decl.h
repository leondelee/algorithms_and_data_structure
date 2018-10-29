
// Created by llw on 18-10-20.
//
#ifndef DEVOIR_DECL_H
#define DEVOIR_DECL_H

enum Directions {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

struct State {
    int x, y;
    Directions intention;
};

template <typename T> class Queue {
public:
    int max_size;
    int front;
    int rear;
    T* list_array;
    Queue(int size);
    void enqueue(const T &element);
    T dequeue();
    int get_queue_length();
    void output_queue();
};

class Agent {
private:
    int maze_size;
    int min_steps;
    vector<Directions>
public:
    Queue<int>
};
#endif
