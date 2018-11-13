//
// Created by speit on 18-11-13.
//
#include <iostream>
#include <cassert>

#include "BTPN.h"

using namespace std;

template <typename Key, typename E>
class BinarySearchTree: public BinaryTreeNode<Key, E> {
private:
    BinaryTreeNode<Key, E>* root;
    int num_of_nodes = 0;
public:
    void clear(BinaryTreeNode<Key, E>* root){
        if(root == NULL) return;
        this->clear(this->get_left_node_ptr());
        this->clear(this->get_right_node_ptr());
        root = NULL;
        this->num_of_nodes -= 2;
        assert(this->num_of_nodes >= 0);
    }

    BinaryTreeNode<Key, E>* find(BinaryTreeNode<Key, E>* root, Key& key) const {
        if(this->root == NULL) {
            cout << "Not found" << endl;
            return root;
        }
        if(this->root->get_key() > key) this->find(this->get_left_node_ptr(), key);
        else if(this->root->get_key() < key) this->find(this->get_right_node_ptr(), key);
        else {
            cout << "Found " << key << " at address " << root << "." << endl;
            return root;
        }
    }
};