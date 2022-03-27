#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

// A node in the red-black tree that stores a double
class RBTNode {
public:
    enum class Child {
        LEFT, RIGHT
    };

    // Whether the node is red (false denotes black)
    bool red = true;
    double key;
    RBTNode* left = nullptr;
    RBTNode* right = nullptr;
    RBTNode* parent = nullptr;
    int height = 0;

    RBTNode(double nodeKey) {
        key = nodeKey;
    }

    RBTNode(double nodeKey, RBTNode* parentNode, bool isRed);
    RBTNode(double nodeKey, RBTNode* parentNode, bool isRed, RBTNode* leftChild, RBTNode* rightChild);

    bool areBothChildrenBlack();
    int count();
    RBTNode* getGrandparent();
    RBTNode* getPredecessor();
    RBTNode* getSibling();
    RBTNode* getUncle();
    bool isBlack();
    bool isRed();
    bool replaceChild(RBTNode* currentChild, RBTNode* newChild);
    bool setChild(Child whichChild, RBTNode* child);
    void updateHeight();
};

// A red-black tree that can only insert
class RedBlackTree
{
public:
    RedBlackTree() {};
    ~RedBlackTree();

    // Insert a new element and rebalance the tree
    void insert(RBTNode* node);
    void insertionBalance(RBTNode* node);
    RBTNode* rotateLeft(RBTNode* node);
    RBTNode* rotateRight(RBTNode* node);

private:
    RBTNode* root = nullptr;
    void deleteTree(RBTNode* node);
};

#endif // !REDBLACKTREE_H