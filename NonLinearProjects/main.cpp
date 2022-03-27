#include "RedBlackTree.h"
#include "AVLTree.h"
#include <iostream>
#include <random>

using namespace std;

int main()
{
	double randomN = 0.0;

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
	}

	return 0;
}
