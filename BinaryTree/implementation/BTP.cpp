//
// Created by speit on 18-11-10.
// implementation of pointer version of binary tree
//
#include <iostream>

template <typename Key, typename E>
class BinaryTree {
private:
    Key key;
    E value;
    BinaryTree<Key, E>* left_node_ptr;
    BinaryTree<Key, E>* right_node_ptr;
public:
    BinaryTree() {
        left_node_ptr = nullptr;
        right_node_ptr = nullptr;
    }
    BinaryTree(Key arg_key, E arg_value, BinaryTree* arg_left_node_ptr, BinaryTree* arg_right_node_ptr) {
        key = arg_key;
        value = arg_value;
        left_node_ptr = arg_left_node_ptr;
        right_node_ptr = arg_right_node_ptr;
    }

    E get_value() const { return value;}
    void set_value(const E& element) { value = element;}
    BinaryTree<Key, E>* get_left_node_ptr() const { return left_node_ptr;}
    void set_left_node_ptr(BinaryTree<Key, E>* arg_left_node_ptr) { left_node_ptr = arg_left_node_ptr;}
    BinaryTree<Key, E>* get_right_node_ptr() const { return right_node_ptr;}
    void set_right_node_ptr(BinaryTree<Key, E>* arg_right_node_ptr) { right_node_ptr = arg_right_node_ptr;}
    bool is_leaf() { return (left_node_ptr == nullptr) && (right_node_ptr == nullptr);}

    // overloading new and delete
//    void *operator new(size_t) {
//        return ::new BinaryTree<Key, E>;
//    }
};
