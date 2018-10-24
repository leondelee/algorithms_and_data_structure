
// Created by llw on 18-10-20.
//
#ifndef DEVOIR_DECL_H
#define DEVOIR_DECL_H

<template T> class Queue {
private:
    int max_size;
    int front;
    int rear;
    T* list_array;
public:
    Queue(int size);
    ~Queue();
    void enqueue(const T &element);
    T delete_queue();
    int length();
};
#endif DEVOIR_DECL_H
