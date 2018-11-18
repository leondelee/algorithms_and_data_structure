//
// Created by llw on 18-11-18.
//

#include "../../my_tools/tools.h"
#include "implementation/HuffmanTree.h"

using namespace std;

int main() {
    FreqStructure<char> fs1 = {'a', 8};
    FreqStructure<char> fs2 = {'b', 3};
    FreqStructure<char> fs3 = {'c', - 5};
    FreqStructure<char> fs4 = {'d', 100};
    FreqStructure<char>* fsa[4] = {&fs1, &fs2, &fs3, &fs4};
    auto a = get_huffman_tree(fsa, 4);
    my_cout(a->get_root()->);
}

