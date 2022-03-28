#include "RedBlackTree.h"
#include <algorithm>

RBTNode::RBTNode(double nodeKey, RBTNode* parentNode, bool isRed) {
    key = nodeKey;
    parent = parentNode;
    red = isRed;
    left = nullptr;
    right = nullptr;
}

RBTNode::RBTNode(double nodeKey, RBTNode* parentNode, bool isRed, RBTNode* leftChild, RBTNode* rightChild) {
    key = nodeKey;
    parent = parentNode;
    left = leftChild;
    right = rightChild;
    red = isRed;
}

RedBlackTree::~RedBlackTree() {
    deleteTree(root);
}

bool RBTNode::areBothChildrenBlack() {
    if (left != nullptr && left->isRed()) {
        return false;
    }
    if (right != nullptr && right->isRed()) {
        return false;
    }
    return true;
}

int RBTNode::count() {
    int count = 1;
    if (left != nullptr) {
        count += left->count();
    }
    if (right != nullptr) {
        count += right->count();
    }
    return count;
}

RBTNode* RBTNode::getGrandparent() {
    if (parent == nullptr) {
        return nullptr;
    }
    return parent->parent;
}

RBTNode* RBTNode::getPredecessor() {
    RBTNode* node = left;
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

RBTNode* RBTNode::getSibling() {
    if (parent != nullptr) {
        if (this == parent->left) {
            return parent->right;
        }
        return parent->left;
    }
    return nullptr;
}

RBTNode* RBTNode::getUncle() {
    RBTNode* grandparent = getGrandparent();
    if (grandparent == nullptr) {
        return nullptr;
    }
    if (grandparent->left == parent) {
        return grandparent->right;
    }
    return grandparent->left;
}

bool RBTNode::isBlack() {
    return !red;
}

bool RBTNode::isRed() {
    return red;
}

bool RBTNode::replaceChild(RBTNode* currentChild, RBTNode* newChild) {
    if (left == currentChild) {
        return setChild(Child::LEFT, newChild);
    }
    else if (right == currentChild) {
        return setChild(Child::RIGHT, newChild);
    }
    return false;
}

bool RBTNode::setChild(Child whichChild, RBTNode* child) {
    if (whichChild == Child::LEFT) {
        left = child;
    }
    else {
        right = child;
    }

    if (child != nullptr) {
        child->parent = this;
    }

    updateHeight();

    return true;
}

void RBTNode::updateHeight()
{
    int leftHeight = -1;

    if (left != nullptr)
    {
        leftHeight = left->height;
    }

    int rightHeight = -1;

    if (right != nullptr)
    {
        rightHeight = right->height;
    }

    height = std::max(leftHeight, rightHeight) + 1;
}

void RedBlackTree::insert(RBTNode* node) {
    if (root == nullptr) {
        root = node;
    }
    else {
        RBTNode* currentNode = root;
        while (currentNode != nullptr) {
            if (node->key < currentNode->key) {
                if (currentNode->left == nullptr) {
                    currentNode->setChild(RBTNode::Child::LEFT, node);
                    break;
                }
                else {
                    currentNode = currentNode->left;
                }
            }
            else {
                if (currentNode->right == nullptr) {
                    currentNode->setChild(RBTNode::Child::RIGHT, node);
                    break;
                }
                else {
                    currentNode = currentNode->right;
                }
            }
        }
    }

    node->red = true;
    insertionBalance(node);
    while (node->parent != nullptr)
    {
        node->updateHeight();
        node = node->parent;
    }
}

void RedBlackTree::insertionBalance(RBTNode* node) {
    node->updateHeight();

    if (node->parent == nullptr) {
        node->red = false;
        return;
    }

    if (node->parent->isBlack()) {
        return;
    }

    RBTNode* parent = node->parent;
    RBTNode* grandparent = node->getGrandparent();
    RBTNode* uncle = node->getUncle();

    if (uncle != nullptr && uncle->isRed()) {
        parent->red = uncle->red = false;
        grandparent->red = true;
        insertionBalance(grandparent);
        return;
    }

    if (node == parent->right && parent == grandparent->left) {
        rotateLeft(parent);
        node = parent;
        parent = node->parent;
    }
    else if (node == parent->left && parent == grandparent->right) {
        rotateRight(parent);
        node = parent;
        parent = node->parent;
    }

    parent->red = false;
    grandparent->red = true;

    if (node == parent->left) {
        rotateRight(grandparent);
    }
    else {
        rotateLeft(grandparent);
    }
}

RBTNode* RedBlackTree::rotateLeft(RBTNode* node) {
    RBTNode* rightLeftChild = node->right->left;

    if (node->parent != nullptr) {
        node->parent->replaceChild(node, node->right);
    }
    else {
        root = node->right;
        root->parent = nullptr;
    }

    node->right->setChild(RBTNode::Child::LEFT, node);

    node->setChild(RBTNode::Child::RIGHT, rightLeftChild);

    return node->parent;
}

RBTNode* RedBlackTree::rotateRight(RBTNode* node) {
    RBTNode* leftRightChild = node->left->right;

    if (node->parent != nullptr) {
        node->parent->replaceChild(node, node->left);
    }
    else {
        root = node->left;
        root->parent = nullptr;
    }

    node->left->setChild(RBTNode::Child::RIGHT, node);

    node->setChild(RBTNode::Child::LEFT, leftRightChild);

    return node->parent;
}

void RedBlackTree::deleteTree(RBTNode* node) {
    // Recursively remove all nodes in the BST (used by the destructor). 
    // By doing this recursively, we start removing nodes from the bottom
    // of the tree (leaf nodes), which is most efficiently because it does
    // not require replacing any nodes.

    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}