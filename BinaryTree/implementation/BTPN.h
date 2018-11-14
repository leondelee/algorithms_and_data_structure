//
// Created by speit on 18-11-10.
// implementation of pointer version of binary tree
//
#ifndef BTPN_H_
#define BTPN_H_

#include <iostream>

using namespace std;

template <typename Key, typename E>
class BinaryTreeNode {
private:
    Key key;
    E value;
    BinaryTreeNode<Key, E>* left_node_ptr;
    BinaryTreeNode<Key, E>* right_node_ptr;
public:
    BinaryTreeNode() { }

    BinaryTreeNode<Key, E>* get_current_node_address() { return this; }
    E get_value() const { return this->value; }
    Key get_key() const { return this->key; }
    void set_value(const E& element) { this->value = element; }
    void set_key(const Key& key) { this->key = key; }

    BinaryTreeNode<Key, E>* get_left_node_ptr() const { return left_node_ptr;}
    void set_left_node_ptr(BinaryTreeNode<Key, E>* arg_left_node_ptr) { left_node_ptr = arg_left_node_ptr;}
    BinaryTreeNode<Key, E>* get_right_node_ptr() const { return right_node_ptr;}
    void set_right_node_ptr(BinaryTreeNode<Key, E>* arg_right_node_ptr) { right_node_ptr = arg_right_node_ptr;}
    bool is_leaf() { return (this->left_node_ptr ==   NULL) && (this->right_node_ptr == NULL);}

    // overloading new and delete
//    void *operator new(size_t) {
//        return ::new BinaryTreeNode<Key, E>;
//    }
};

#endif
