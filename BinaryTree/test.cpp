//
// Created by speit on 18-11-10.
//
#include <iostream>

using namespace std;

class Test {
public:
    Test() {cout << 1 << endl;}
    Test(int a) {cout << a << endl;}
};

int main() {
    int* a;
    bool b = (a == nullptr);
    cout << b << endl;
}