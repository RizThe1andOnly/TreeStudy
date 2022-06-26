#include <vector>

/* Constants */
/* For Binary Trees */
#define BINARYNODE_LEFT 0
#define BINARYNODE_RIGHT 1
#define BINARYNODE_CHILDREN_LENGTH 2

/* Class Definitions */
#ifndef TREESTRUCTS_H
#define TREESTRUCTS_H

class Node
{
    public:
        Node(){}
        std::vector<Node*> children;
};

class BinaryIntNode: private Node
{
    private:
        int data;

    public:
        /* Default constructor, will construct node with value of 0 for data */
        BinaryIntNode();
        BinaryIntNode(int dataInput);

        /* Destructor */
        ~BinaryIntNode();

        /* Constructor helper; common to all constructors. Will be used to set the children vector size and the data from constructor args. */
        void constructorHelper(int dataInput);
    
        /* getters */
        BinaryIntNode* getRight();
        BinaryIntNode* getLeft();
        int getData();

        /* setters */
        /* - Left setters */
        void setLeft(int data);
        void setLeft(BinaryIntNode* leftNode);
        /* - Right setters */
        void setRight(int data);
        void setRight(BinaryIntNode* rightNode);
};


#endif
