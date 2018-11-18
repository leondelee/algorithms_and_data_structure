//
// Created by speit on 18-11-13.
//
#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <cassert>

#include "BTPN.h"

using namespace std;

template <typename Key, typename E>
struct NodeDataStr {
    Key key;
    E value;
};

template <typename Key, typename E>
class BinarySearchTree: public BinaryTreeNode<Key, E> {
private:
    BinaryTreeNode<Key, E>* root;
    int num_of_nodes;

    void private_clear(BinaryTreeNode<Key, E>*& root){
        if(root == NULL) return;
        BinaryTreeNode<Key, E>*& left_node_ptr = root->get_left_node_ptr();
        BinaryTreeNode<Key, E>*& right_node_ptr = root->get_right_node_ptr();
        this->private_clear(left_node_ptr);
        this->private_clear(right_node_ptr);
        root = NULL;
        this->num_of_nodes -= 1;
        assert(this->num_of_nodes >= 0);
    }

    BinaryTreeNode<Key, E>*& private_find(BinaryTreeNode<Key, E>*& root, Key& key, bool verbose = false) {
        if(root == NULL) {
            cout << "Record with key \"" << key <<  "\" Not Found." << endl;
            return root;
        }
        else if(root->get_key() > key) this->private_find(root->get_left_node_ptr(), key);
        else if(root->get_key() < key) this->private_find(root->get_right_node_ptr(), key);
        else {
            if(verbose) cout << "Found " << key << " at address " << root << "." << endl;
            return root;
        }
    }

    void private_insert(BinaryTreeNode<Key, E>*& root, Key& key, E& value) {
        if(root == NULL) {
            root = new BinaryTreeNode<Key, E>;
            root->set_value(value);
            root->set_key(key);
            this->num_of_nodes += 1;
            return;
        }
        else if(key < root->get_key()) {
            if(root->get_left_node_ptr() == NULL) {
                BinaryTreeNode<Key, E>* left_node_ptr = new BinaryTreeNode<Key, E>;
                root->set_left_node_ptr(left_node_ptr);
                root->get_left_node_ptr()->set_key(key);
                root->get_left_node_ptr()->set_value(value);
                this->num_of_nodes += 1;
                return;
            }
            BinaryTreeNode<Key, E>* left_node_ptr = root->get_left_node_ptr();
            this->private_insert(left_node_ptr, key, value);
            return;
        }
        else if(key >= root->get_key()) {
            if(root->get_right_node_ptr() == NULL) {
                BinaryTreeNode<Key, E>* right_node_ptr = new BinaryTreeNode<Key, E>;
                root->set_right_node_ptr(right_node_ptr);
                root->get_right_node_ptr()->set_key(key);
                root->get_right_node_ptr()->set_value(value);
                this->num_of_nodes += 1;
                return;
            }
            BinaryTreeNode<Key, E>* right_node_ptr = root->get_right_node_ptr();
            this->private_insert(right_node_ptr, key, value);
            return;
        }
        // else if(key == root->get_key()) cout << "Record with key \"" << key << "\" already exist!" << endl;
    }

    BinaryTreeNode<Key, E>*& private_get_min(BinaryTreeNode<Key, E>*& root) {
        if(root->get_left_node_ptr() == NULL) return root;
        else {
            return this->private_get_min(root->get_left_node_ptr());
        }
    }

    NodeDataStr<Key, E>* private_delete_min(BinaryTreeNode<Key, E>*& root) {
        BinaryTreeNode<Key, E>*& min_node = this->private_get_min(root);
        if(min_node == NULL) return NULL;
        assert(min_node->get_left_node_ptr() == NULL);
        NodeDataStr<Key, E>* nds = new NodeDataStr<Key, E>;
        nds->key = min_node->get_key();
        nds->value = min_node->get_value();
        min_node = min_node->get_right_node_ptr();
        return nds;
    }

    void private_remove(Key key) {
        BinaryTreeNode<Key, E>*& root_found = this->private_find(this->root, key);
        NodeDataStr<Key, E>* min_node_str = private_delete_min(root_found);
        if(min_node_str == NULL) return;
        root_found->set_key(min_node_str->key);
        root_found->set_value(min_node_str->value);
        return;
    }
public:
    BinarySearchTree() {
        this->root = NULL;
        this->num_of_nodes = 0;
    }

    int get_nodes_number() { return this->num_of_nodes; }

    BinaryTreeNode<Key, E>* get_root() const { return this->root; }

    void clear(BinaryTreeNode<Key, E>*& root) { this->private_clear(root); }

    BinaryTreeNode<Key, E>*& find(Key& key) { return this->private_find(this->root, key, true); }

    void insert(Key& key, E& value) { this->private_insert(this->root, key, value); }

    BinaryTreeNode<Key, E>* get_min() {
        return this->private_get_min(this->root);
    }

    NodeDataStr<Key, E>* delete_min() {
        return this->private_delete_min(this->root);
    }

    void remove(Key key) { this->private_remove(key); }
};

#endif