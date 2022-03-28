#include "RedBlackTree.h"
#include "AVLTree.h"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = start;
	auto totalTimeAVL = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	auto totalTimeRBT = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	for (int i = 100; i < 100001; i *= 10)
	{
		for (int j = 0; j < 10; j++)
		{
			std::vector<double> randomList(i);

			for (int l = 0; l < i; l++)
			{
				randomList.at(l) = (double)rand() / RAND_MAX;
			}

			AVLTree a;
			Node* aRoot = new Node(randomList.at(0));
			a.insert(aRoot);
			RedBlackTree b;
			RBTNode* bRoot = new RBTNode(randomList.at(0));
			b.insert(bRoot);
			
			start = std::chrono::high_resolution_clock::now();
			for (int m = 1; m < i; m++)
			{
				a.insert(new Node(randomList.at(m)));
			}
			stop = std::chrono::high_resolution_clock::now();
			totalTimeAVL = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

			start = std::chrono::high_resolution_clock::now();
			for (int k = 1; k < i; k++)
			{
				b.insert(new RBTNode(randomList.at(k)));
			}
			stop = std::chrono::high_resolution_clock::now();
			totalTimeRBT = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
			
			while (aRoot->parent != nullptr)
			{
				aRoot = aRoot->parent;
			}
			
			while (bRoot->parent != nullptr)
			{
				bRoot = bRoot->parent;
			}

			cout << "AVL unsorted:   " << aRoot->height << "  :  " << totalTimeAVL.count() << endl;
			cout << "RBT unsorted:   " << bRoot->height << "  :  " << totalTimeRBT.count() << "\n" << endl;
		}

		for (int j = 0; j < 10; j++)
		{
			std::vector<double> sortedList(i);

			for (int l = 0; l < i; l++)
			{
				sortedList.at(l) = (double)rand() / RAND_MAX;
			}

			sort(sortedList.begin(), sortedList.end());
			AVLTree a;
			Node* aRoot = new Node(sortedList.at(0));
			a.insert(aRoot);
			RedBlackTree b;
			RBTNode* bRoot = new RBTNode(sortedList.at(0));
			b.insert(bRoot);

			start = std::chrono::high_resolution_clock::now();
			for (int m = 1; m < i; m++)
			{
				a.insert(new Node(sortedList.at(m)));
			}
			stop = std::chrono::high_resolution_clock::now();
			totalTimeAVL = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

			start = std::chrono::high_resolution_clock::now();
			for (int k = 1; k < i; k++)
			{
				b.insert(new RBTNode(sortedList.at(k)));
			}
			stop = std::chrono::high_resolution_clock::now();
			totalTimeRBT = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

			while (aRoot->parent != nullptr)
			{
				aRoot = aRoot->parent;
			}

			while (bRoot->parent != nullptr)
			{
				bRoot = bRoot->parent;
			}

			cout << "AVL sorted:   " << aRoot->height << "  :  " << totalTimeAVL.count() << endl;
			cout << "RBT sorted:   " << bRoot->height << "  :  " << totalTimeRBT.count() << "\n" << endl;
		}

		for (int j = 0; j < 10; j++)
		{
			std::vector<double> semiSortedList(i);

			for (int l = 0; l < i; l++)
			{
				semiSortedList.at(l) = (double)rand() / RAND_MAX;
			}

			sort(semiSortedList.begin() + semiSortedList.size() / 4, semiSortedList.end() - semiSortedList.size() / 4);
			AVLTree a;
			Node* aRoot = new Node(semiSortedList.at(0));
			a.insert(aRoot);
			RedBlackTree b;
			RBTNode* bRoot = new RBTNode(semiSortedList.at(0));
			b.insert(bRoot);

			start = std::chrono::high_resolution_clock::now();
			for (int m = 1; m < i; m++)
			{
				a.insert(new Node(semiSortedList.at(m)));
			}
			stop = std::chrono::high_resolution_clock::now();
			totalTimeAVL = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

			start = std::chrono::high_resolution_clock::now();
			for (int k = 1; k < i; k++)
			{
				b.insert(new RBTNode(semiSortedList.at(k)));
			}
			stop = std::chrono::high_resolution_clock::now();
			totalTimeRBT = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

			while (aRoot->parent != nullptr)
			{
				aRoot = aRoot->parent;
			}

			while (bRoot->parent != nullptr)
			{
				bRoot = bRoot->parent;
			}

			cout << "AVL semi-sorted:   " << aRoot->height << "  :  " << totalTimeAVL.count() << endl;
			cout << "RBT semi-sorted:   " << bRoot->height << "  :  " << totalTimeRBT.count() << "\n" << endl;
		}
	}

	return 0;
}
