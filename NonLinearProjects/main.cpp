#include "RedBlackTree.h"
#include "AVLTree.h"
#include <iostream>
#include <random>

using namespace std;

int main()
{
	/*double randomN = 0.0;

	for (int i = 100; i < 100001; i *= 10)
	{
		for (int j = 0; j < 10; j++)
		{
			randomN = (double)rand() / RAND_MAX;
			AVLTree a;
			Node* aRoot = new Node(randomN);
			a.insert(aRoot);
			RedBlackTree b;
			RBTNode* bRoot = new RBTNode(randomN);
			b.insert(bRoot);

			for (int k = 1; k < i; k++)
			{
				randomN = (double)rand() / RAND_MAX;
				a.insert(new Node(randomN));
				b.insert(new RBTNode(randomN));
			}
			
			while (aRoot->parent != nullptr)
			{
				aRoot = aRoot->parent;
			}
			
			while (bRoot->parent != nullptr)
			{
				bRoot = bRoot->parent;
			}

			cout << aRoot->height << "  :  " << bRoot->height << endl;
		}

		cout << "\n\nNext N" << endl;
	}*/

	//RedBlackTree rbt;
	//RBTNode* rbtRoot = new RBTNode(46);
	//rbt.insert(rbtRoot);
	//rbt.insert(new RBTNode(28));
	//rbt.insert(new RBTNode(64));
	//rbt.insert(new RBTNode(19));
	//rbt.insert(new RBTNode(37));
	//rbt.insert(new RBTNode(55));
	//rbt.insert(new RBTNode(73));
	//rbt.insert(new RBTNode(91));

	//while (rbtRoot->parent != nullptr)
	//{
	//	rbtRoot = rbtRoot->parent;
	//}

	///*std::cout << rbtRoot->key << std::endl;
	//std::cout << rbtRoot->left->key << " " << rbtRoot->right->key << std::endl;
	//std::cout << rbtRoot->right->left->key << " " << rbtRoot->right->right->key << endl;
	//std::cout << rbtRoot->left->left->key << " " << rbtRoot->left->right->key << std::endl;
	//cout << rbtRoot->right->right->right->key;*/


	//cout << rbtRoot->height << endl;

	return 0;
}
