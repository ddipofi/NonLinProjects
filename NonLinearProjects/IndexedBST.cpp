#include "IndexedBST.h"

IndexedBST::~IndexedBST() {
	deleteTree(root);
}

void IndexedBST::deleteTree(Node* node) {
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

Node* IndexedBST::search(double desiredKey) {
	Node* cur = root;
	while (cur != nullptr) {
		// Return the node if the key matches
		if (cur->key == desiredKey) {
			return cur;
		}

		// Navigate to the left if the search key is 
		// less than the node's key.
		else if (desiredKey < cur->key) {
			cur = cur->left;
		}

		// Navigate to the right if the search key is 
		// greater than the node's key.
		else {
			cur = cur->right;
		}
	}

	// The key was not found in the tree.
	return nullptr;
}

Node* IndexedBST::at(int index) {
	Node* cur = root;
	while (cur != nullptr) {
		if (index == cur->leftSize)
			return cur;     // Found
		else if (index < cur->leftSize)
			cur = cur->left;    // index is in left subtree
		else {
			// index is in right subtree
			index = index - cur->leftSize - 1;
			cur = cur->right;
		}
	}

	return nullptr;
}

void IndexedBST::insert(Node* node)
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
				cur->leftSize++;

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
}

bool IndexedBST::remove(double key)
{
	Node* par = nullptr;
	Node* cur = root;

	while (cur != nullptr)
	{
		if (cur->key == key)
		{
			if (cur->left == nullptr && cur->right == nullptr)
			{
				if (par == nullptr)
				{
					root = nullptr;
				}
				else if (par->left == cur)
				{
					par->left = nullptr;
				}
				else
				{
					par->right = nullptr;
				}
			}
			else if (cur->right == nullptr)
			{
				if (par == nullptr)
				{
					root = cur->left;
				}
				else if (par->left == cur)
				{
					par->left = cur->left;
				}
				else
				{
					par->right = cur->left;
				}
			}
			else if (cur->left == nullptr)
			{
				if (par == nullptr)
				{
					root = cur->right;
				}
				else if (par->left == cur)
				{
					par->left = cur->right;
				}
				else
				{
					par->right = cur->right;
				}
			}
			else
			{
				Node* suc = cur->right;

				while (suc->left != nullptr)
				{
					suc = suc->left;
				}

				double successorData = suc->key;
				remove(successorData);
				cur->key = successorData;
			}

			return true;
		}
		else if (cur->key < key)
		{
			par = cur;
			cur = cur->right;
		}
		else
		{
			par = cur;
			par->leftSize--;
			cur = cur->left;
		}
	}

	return false;
}