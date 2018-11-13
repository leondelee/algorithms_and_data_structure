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
    // void Fun(int a) const {value = 3;}
};

int main() {
    BinarySearchTree<int, float> bst;
    bst.clear(bst.get_root());
    int a = 1;
    bst.find(bst.get_root(), a);
    cout << bst.get_root() << endl;
}