//
// Created by speit on 18-11-10.
//
#include <iostream>

#include "../my_tools/tools.h"
#include "implementation/BST.h"

using namespace std;

class Test {
public:
    int value;
    Test() {cout << 1 << endl;}
    Test(int a) {a = 2; cout << a << endl;}
};

void test_ref(int& a) {
    a += 1;
}

int main() {
    BinarySearchTree<int, float> bst;
    int a1 = 1, a2 = 2, a3 = - 3;
    float b = 0.1;
    for(int i = 10; i != 0; i--) {
        bst.insert(i, b);
    }
    bst.remove(2);
    bst.get_root()->mid_order(bst.get_root());
}