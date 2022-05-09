#include <iostream>

#include "TreeStructs.h"


int main() {
    int x = 0;
    int y = 2;
    int z = x + y;

    std::cout << "Trying to test out debug " << z << std::endl;

    BinaryNode<int> bn;
    bn.setRight();

    return 0;
}