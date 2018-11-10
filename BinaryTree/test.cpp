//
// Created by speit on 18-11-10.
//
#include <iostream>

#include "implementation/BTP.cpp"

using namespace std;

class Test {
public:
    Test() {cout << 1 << endl;}
    Test(int a) {cout << a << endl;}
};

int main() {
    BinaryTree<int, int>* tree = new BinaryTree<int, int>[5];
    BinaryTree<int, int> tree1 = *(tree + 1);
    BinaryTree<int, int>* ptr = & tree1;
    tree1.set_left_node_ptr(ptr);
    cout << tree1.get_left_node_ptr() << endl;
    cout << tree1.get_right_node_ptr() << endl;
}