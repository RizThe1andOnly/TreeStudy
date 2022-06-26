#include <iostream>

#include "TreeStructs.h"


int main() {

    /* Create the root */
    BinaryIntNode* root = new BinaryIntNode(0);

    /* Set the children */
    root->setLeft(1);
    root->setRight(2);

    /* Try and get the children */
    BinaryIntNode* leftKid = root->getLeft();
    BinaryIntNode* rightKid = root->getRight();

    /* Print out the data in retrieved node. */
    std::cout << rightKid->getData() << std::endl;
    std::cout << leftKid->getData() << std::endl;

    delete(root);

    return 0;
}