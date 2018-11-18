//
// Created by speit on 18-11-18.
//

#ifndef DEVOIR_HUFFMANTREE_H
#define DEVOIR_HUFFMANTREE_H

#include "../../../my_tools/tools.h"
#include "BST.h"

#define TYPE_HFN HuffmanNode<E>*
#define TYPE_HFT HuffmanTree<E>*

template <typename E>
class HuffmanNode {
public:
    virtual int get_weight() = 0;
    virtual bool is_leaf() = 0;
};

template <typename E>
class HuffmanLeafNode: public HuffmanNode<E> {
private:
    E item;
    int weight;
public:
    HuffmanLeafNode(E it, int wgt) {
        this->item = it;
        this->weight = wgt;
    }
    int get_weight() { return this->weight; }
    bool is_leaf() { return true; }
    void set_item(E it) { this->item = it; }
    void set_weight(int wgt) { this->weight = wgt; }
};

template <typename E> 
class HuffmanIntNode: public HuffmanNode<E> {
private:
    TYPE_HFN left_node;
    TYPE_HFN right_node;
public:
    HuffmanIntNode(TYPE_HFN ln, TYPE_HFN rn) {
        this->left_node = ln;
        this->right_node = rn;
    }
    int get_weight() { return this->left_node->get_weight() + this->right_node->get_weight(); }
    bool is_leaf() { return false; }
    void set_left_node(TYPE_HFN node) { this->left_node = node; }
    TYPE_HFN get_left_node() { return this->left_node; }
    void set_right_node(TYPE_HFN node) { this->right_node = node; }
    TYPE_HFN get_right_node() { return this->right_node; }
};

template <typename E>
class HuffmanTree: public HuffmanNode<E> {
private:
    HuffmanNode<E>* root;
public:
    HuffmanTree(E it, int wgt) { this->root = new HuffmanLeafNode<E>(it, wgt); }
    HuffmanTree(TYPE_HFT lt, TYPE_HFT rt) { this->root = new HuffmanIntNode<E>(lt->root, rt->root); }
    TYPE_HFT get_root() { return this->root; }
    int get_weight() { return root->get_weight(); }
    bool is_leaf() { return this->root->is_leaf(); }
};

template <typename E>
struct FreqStructure {
    E item;
    int weight;
};

template <typename E>
HuffmanTree<E>* get_huffman_tree(FreqStructure<E>** FreqStructureArray, int count) {
    if(!count) return NULL;
    BinarySearchTree<int, HuffmanTree<E>*> bft_bst;
    for(int i = 0; i < count; i ++) {
        HuffmanTree<E>* temp_hfn = new HuffmanTree<E>(FreqStructureArray[i]->item, FreqStructureArray[i]->weight);
        bft_bst.insert(FreqStructureArray[i]->weight, temp_hfn);
    }
    while(bft_bst.get_nodes_number() > 1) {
        HuffmanTree<E>*& temp_hf1 = bft_bst.delete_min()->value;
        HuffmanTree<E>*& temp_hf2 = bft_bst.delete_min()->value;
        HuffmanTree<E>* temp_hf3 = new HuffmanTree<E>(temp_hf1, temp_hf2);
        bft_bst.insert(temp_hf3->get_weight(), temp_hf3);
    }
    my_assert(bft_bst.get_nodes_number() == 1);
    return bft_bst.get_root()->get_value();
}

//template <typename E>
//void swap_freq_structure(FreqStructure<E>* fs1, FreqStructure<E>* fs2) {
//    FreqStructure<E> temp_fs = *fs1;
//    *fs1 = *fs2;
//    *fs2 = temp_fs;
//    return;
//}
//
//template <typename E>
//void sort_freq_structure_array(FreqStructure<E>* FreqStructureArray[], const int length, bool (*comp) (int, int)) {
//    if(!length) return;
//    for(int index = 1; index < length; index ++) {
//        int temp_index = index - 1;
//        while((*comp) (FreqStructureArray[temp_index]->weight, FreqStructureArray[temp_index + 1]->weight)) {
//            swap_freq_structure(FreqStructureArray[temp_index], FreqStructureArray[temp_index + 1]);
//            temp_index -= 1;
//            if(temp_index < 0) break;
//        }
//    }
//}
#endif //DEVOIR_HUFFMANTREE_H
