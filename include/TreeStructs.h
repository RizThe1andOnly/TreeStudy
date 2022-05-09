#include <vector>

template <typename T>
class Node { 
    public:
        Node();

    private:
        Node(int numChildren);
        int numChildren;
        std::vector<T> children;
        std::vector<T> getChildren();

};

/**
 * @brief Node that will constitue a binary tree. Uses template class to enable usage for different data types.
 * 
 * @tparam T Any class to be the node for a tree.
 */
template <typename T> class BinaryNode : private Node<T> {
    
    public:
        BinaryNode();
        T getRight();
        T getLeft();
        void setRight();
        void setLeft();
    
    private:
        int NUM_CHILDREN = 2;

};

void doSomething();
