//
// Created by speit on 18-11-10.
//
#include <iostream>

#include "implementation/BST.h"

using namespace std;

class Test {
public:
    int value;
    Test() {cout << 1 << endl;}
    Test(int a) {a = 2; cout << a << endl;}
};

int main() {
    BinarySearchTree<int, float> bst;
    bst.clear(bst.get_root());
    int a1 = 1, a2 = 2;
    float b = 0.1;
    bst.insert(a1, b);
    bst.insert(a2, b);
    bst.find(a2);
}