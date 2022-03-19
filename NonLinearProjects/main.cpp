#include "AVLTree.h"
#include <iostream>

using namespace std;

int main()
{
	// Single rotate left
	AVLTree b;
	Node* bRoot = new Node(2);
	b.insert(bRoot);
	b.insert(new Node(1));
	b.insert(new Node(3));
	b.insert(new Node(4));
	b.insert(new Node(5));
	cout << bRoot->key << endl;
	cout << bRoot->left->key << " " << bRoot->right->key << endl;
	cout << bRoot->right->left->key << " " << bRoot->right->right->key << endl;
	// Rotate left then right
	AVLTree c;
	Node* cRoot = new Node(4);
	c.insert(cRoot);
	c.insert(new Node(3));
	c.insert(new Node(5));
	c.insert(new Node(1));
	c.insert(new Node(2));
	cout << cRoot->key << endl;
	cout << cRoot->left->key << " " << cRoot->right->key << endl;
	cout << cRoot->left->left->key << " " << cRoot->left->right->key << endl;

	return 0;
}