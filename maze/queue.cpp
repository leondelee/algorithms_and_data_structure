//
// Created by llw on 18-10-20.
//
#include <iostream>
#include <assert.h>

#include "decl.h"

using namespace std;

template <typename T> Queue<T>::Queue(int size) {
    this->max_size = size + 1;
    this->front = 0;
    this->rear = this->max_size - 1;
    this->list_array =new T[this->max_size];
    cout << "A queue has been initialized!" << endl;
}

template <typename T> void Queue<T>::enqueue(const T &element) {
    assert((this->rear + 2) % this->max_size != this->front && "This queue is full!");
    this->rear = (this->rear + 1) % this->max_size;
    this->list_array[this->rear] = element;
}

template <typename T> T Queue<T>::dequeue() {
    assert(this->get_queue_length() != 0 && "The queue is empty!");
    T front_ele = this->list_array[this->front];
    this->front = (this->front + 1) % this->max_size;
    return front_ele;
}

template <typename T> int Queue<T>::get_queue_length() {
    return (this->rear + this->max_size - this->front + 1) % this->max_size;
}

template <typename T> void Queue<T>::output_queue() {
    assert(this->get_queue_length() != 0 && "Print empty queue!");
    cout << "The elements in this queue are: ";
    for(int i = this->front; i != this->rear; i = (i + 1) % this->max_size) cout << this->list_array[i] << ", ";
    cout << this->list_array[this->rear] << endl;
}