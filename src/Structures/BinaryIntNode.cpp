#include "TreeStructs.h"


/**
 * @brief Functions called by the constructor to set the data attributes of the object.
 * Sets the data attribute and children vector's size to two.
 * 
 * @param dataInput 
 */
void BinaryIntNode::constructorHelper(int dataInput)
{
    children.resize(2);
    data = dataInput;
}

/**
 * @brief Construct a new Binary Int Node:: Binary Int Node object.
 * Default constructor which will create node with data = 0.
 * 
 */
BinaryIntNode::BinaryIntNode()
{
    constructorHelper(0);
}

/**
 * @brief Construct a new Binary Int Node:: Binary Int Node object.
 * Constructor which will create object with the data equal to dataInput.
 * 
 * @param dataInput 
 */
BinaryIntNode::BinaryIntNode(int dataInput)
{
    constructorHelper(dataInput);
}

/**
 * @brief Destroy the Binary Int Node:: Binary Int Node object
 * 
 */
BinaryIntNode::~BinaryIntNode()
{
    /* Delete each of the items that the children vector's pointers point to. */
    for(int i=0; i<BINARYNODE_CHILDREN_LENGTH; i++)
    {
        BinaryIntNode* toBeDeleted = (BinaryIntNode*)children[i];
        delete(toBeDeleted);
    }

    /* Clear out the vector and resize it to make sure all memory is de-allocated. */
    children.clear();
    children.resize(0);
}

/**
 * @brief 
 * 
 * @param data 
 */
void BinaryIntNode::setLeft(int data)
{
    BinaryIntNode* leftNode = new BinaryIntNode(data);
    children[BINARYNODE_LEFT] = leftNode;
}

/**
 * @brief 
 * 
 * @param leftNode 
 */
void BinaryIntNode::setLeft(BinaryIntNode* leftNode)
{
    children[BINARYNODE_LEFT] = leftNode;
}

/**
 * @brief 
 * 
 * @param data 
 */
void BinaryIntNode::setRight(int data)
{
    BinaryIntNode* rightNode = new BinaryIntNode(data);
    children[BINARYNODE_RIGHT] = rightNode;
}

/**
 * @brief 
 * 
 * @param rightNode 
 */
void BinaryIntNode::setRight(BinaryIntNode* rightNode)
{
    children[BINARYNODE_RIGHT] = rightNode;
}

/**
 * @brief 
 * 
 * @return BinaryIntNode* 
 */
BinaryIntNode* BinaryIntNode::getRight()
{
    BinaryIntNode* toBeReturned = (BinaryIntNode*)children[BINARYNODE_RIGHT];
    return toBeReturned;
}

/**
 * @brief 
 * 
 * @return BinaryIntNode* 
 */
BinaryIntNode* BinaryIntNode::getLeft()
{
    BinaryIntNode* toBeReturned = (BinaryIntNode*)children[BINARYNODE_LEFT];
    return toBeReturned;
}

int BinaryIntNode::getData()
{
    return data;
}