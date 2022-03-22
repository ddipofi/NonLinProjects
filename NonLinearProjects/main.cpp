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
			a.insertWithoutRebalance(aRoot);
			AVLTree b;
			Node* bRoot = new Node(randomN);
			b.insert(bRoot);

			for (int k = 1; k < i; k++)
			{
				randomN = (double)rand() / RAND_MAX;
				a.insertWithoutRebalance(new Node(randomN));
				b.insert(new Node(randomN));
			}
			
			while (aRoot->parent != nullptr)
			{
				aRoot = aRoot->parent;
			}
			
			while (bRoot->parent != nullptr)
			{
				bRoot = bRoot->parent;
			}

			cout << maxHeight(aRoot) << "  :  " << bRoot->height << endl;
		}

		cout << "\n\nNext N" << endl;
	}

	return 0;
}

int maxHeight(Node* node)
{
	if (node == nullptr)
		{
			return -1;
		}
	else
	{
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);
		
		if (lDepth > rDepth)
		{
			return(lDepth + 1);
		}
		else
		{
			return(rDepth + 1);
		}
	}
}
