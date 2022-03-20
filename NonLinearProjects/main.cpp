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

			cout << aRoot->height << "  :  " << bRoot->height << endl;
		}

		cout << "\n\nNext N" << endl;
	}

	return 0;
}