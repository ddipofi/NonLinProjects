#include "AVLTree.h"
#include <algorithm>

AVLTree::~AVLTree()
{
    deleteTree(root);
}

int Node::getBalance()
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

	return leftHeight - rightHeight;
}

void Node::updateHeight()
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

bool Node::setChild(child whichChild, Node* child)
{
	if (whichChild == child::LEFT)
	{
		left = child;
	}
	else
	{
		right = child;
	}

	if (child != nullptr)
	{
		child->parent = this;
	}

	updateHeight();

	return true;
}

bool Node::replaceChild(Node* currentChild, Node* newChild)
{
	if (left == currentChild)
	{
		return setChild(child::LEFT, newChild);
	}
	else if (right == currentChild)
	{
		return setChild(child::RIGHT, newChild);
	}

	return false;
}

Node* AVLTree::rotateLeft(Node* node)
{
	Node* rightLeftChild = node->right->left;

	if (node->parent != nullptr)
	{
		node->parent->replaceChild(node, node->right);
	}
	else
	{
		root = node->right;
		root->parent = nullptr;
	}

	node->right->setChild(Node::child::LEFT, node);
	node->setChild(Node::child::RIGHT, rightLeftChild);

	return node->parent;
}

Node* AVLTree::rotateRight(Node* node)
{
	Node* leftRightChild = node->left->right;

	if (node->parent != nullptr)
	{
		node->parent->replaceChild(node, node->left);
	}
	else
	{
		root = node->left;
		root->parent = nullptr;
	}

	node->left->setChild(Node::child::RIGHT, node);
	node->setChild(Node::child::LEFT, leftRightChild);

	return node->parent;
}

Node* AVLTree::rebalance(Node* node)
{
	node->updateHeight();

	if (node->getBalance() == -2)
	{
		if (node->right->getBalance() == 1)
		{
			rotateRight(node->right);
		}

		return rotateLeft(node);
	}
	else if (node->getBalance() == 2)
	{
		if (node->left->getBalance() == -1)
		{
			rotateLeft(node->left);
		}

		return rotateRight(node);
	}

	return node;
}

void AVLTree::insert(Node* node)
{
	if (root == nullptr)
	{
		root = node;
		node->parent = nullptr;
	}
	else
	{
		Node* cur = root;

		while (cur != nullptr)
		{
			if (node->key < cur->key)
			{
				if (cur->left == nullptr)
				{
					cur->left = node;
					node->parent = cur;
					cur = nullptr;
				}
				else
				{
					cur = cur->left;
				}
			}
			else
			{
				if (cur->right == nullptr)
				{
					cur->right = node;
					node->parent = cur;
					cur = nullptr;
				}
				else
				{
					cur = cur->right;
				}
			}
		}

		node = node->parent;

		while (node != nullptr)
		{
			rebalance(node);
			node = node->parent;
		}
	}
}

void AVLTree::insertWithoutRebalance(Node* node)
{
	if (root == nullptr)
	{
		root = node;
		node->parent = nullptr;
	}
	else
	{
		Node* cur = root;

		while (cur != nullptr)
		{
			if (node->key < cur->key)
			{
				if (cur->left == nullptr)
				{
					cur->left = node;
					node->parent = cur;
					cur = nullptr;
				}
				else
				{
					cur = cur->left;
				}
			}
			else
			{
				if (cur->right == nullptr)
				{
					cur->right = node;
					node->parent = cur;
					cur = nullptr;
				}
				else
				{
					cur = cur->right;
				}
			}
		}
	}
	
	while (node != nullptr)
	{
		node->updateHeight();
		node = node->parent;
	}
}

void AVLTree::deleteTree(Node* node)
{
    // Recursively remove all nodes in the BST (used by the destructor). 
    // By doing this recursively, we start removing nodes from the bottom
    // of the tree (leaf nodes), which is most efficiently because it does
    // not require replacing any nodes.

    if (node == nullptr)
    {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
