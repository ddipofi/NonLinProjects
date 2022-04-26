#include <vector>
#include <iostream>
#include <chrono>

// disjointSetForest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

class Node {
public:
	int value = 0;
	int rank = 0;
	Node* parent = nullptr;
	Node(int value) { this->value = value; }
};

void makeSet(Node* element);
Node* findSet(Node* element, bool pathCompression);
void unionSet(Node* element1, Node* element2, bool unionByRank,
	bool pathCompression);
void link(Node* element1, Node* element2);
void printAllElements(std::vector<Node*> elements);

int main()
{
	bool unionByRank = false, pathCompression = true;

	// Test for correctness of functionality
	int numElements = 5;
	std::vector<Node*> elements(numElements);
	// Create vector of pointers to elements
	for (int i = 0; i < numElements; i++)
		elements.at(i) = new Node(i);

	// Make all singleton sets
	for (int i = 0; i < numElements; i++) {
		makeSet(elements.at(i));
	}
	printAllElements(elements);

	// Test a few unions ending up with a single set of all vertices
	unionSet(elements.at(0), elements.at(1), unionByRank, pathCompression);
	printAllElements(elements);
	unionSet(elements.at(0), elements.at(2), unionByRank, pathCompression);
	printAllElements(elements);
	unionSet(elements.at(3), elements.at(4), unionByRank, pathCompression);
	printAllElements(elements);
	unionSet(elements.at(0), elements.at(4), unionByRank, pathCompression);
	printAllElements(elements);

	std::cout << "\n\n\n\n" << std::endl;

	auto start = std::chrono::high_resolution_clock::now();
	auto stop = start;
	auto totalTimeNoH = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	auto totalTimeH = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	for (int i = 100; i < 10001; i *= 10)
	{
		std::vector<Node*> elements2(i);
		std::vector<Node*> elements3(i);

		for (int j = 0; j < i; j++)
		{
			elements2.at(j) = new Node(j);
		}

		for (int m = 0; m < i; m++)
		{
			makeSet(elements2.at(m));
		}

		for (int n = 0; n < i; n++)
		{
			elements3.at(n) = new Node(n);
		}

		for (int o = 0; o < i; o++)
		{
			makeSet(elements3.at(o));
		}

		//runtime without heuristics
		start = std::chrono::high_resolution_clock::now();
		for (int k = 1; k < i; k++)
		{
			unionSet(elements2.at(0), elements2.at(k), false, false);
		}
		stop = std::chrono::high_resolution_clock::now();
		totalTimeNoH = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

		//runtime with heuristics
		start = std::chrono::high_resolution_clock::now();
		for (int l = 1; l < i; l++)
		{
			unionSet(elements3.at(0), elements3.at(l), true, true);
		}
		stop = std::chrono::high_resolution_clock::now();
		totalTimeH = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

		std::cout << "Wall clock without heuristics:  " << totalTimeNoH.count() << std::endl;
		std::cout << "Wall clock with heuristics:  " << totalTimeH.count() << std::endl;
	}

	return 0;
}

void printAllElements(std::vector<Node*> elements) {
	std::cout << "Element  Parent  Set Representative" << std::endl;
	for (int i = 0; i < elements.size(); i++) {
		// Print element and its set representative (should be same as element)
		std::cout << elements.at(i)->value << "  "
			<< elements.at(i)->parent->value << "  " << findSet(elements.at(i), false)->value << std::endl;
	}
}

// Create a set given a single element
void makeSet(Node* element)
{
	element->parent = element;
	element->rank = 0;
}

// Return root for set given an element, using path compression if
// pathCompression is true
Node* findSet(Node* element, bool pathCompression)
{
	if (pathCompression)
	{
		if (element != element->parent)
		{
			element->parent = findSet(element->parent, true);
		}

		return element->parent;
	}
	else
	{
		if (element != element->parent)
		{
			findSet(element->parent, false);
		}
		else
		{
			return element->parent;
		}
	}
}

// Take the union of two sets given an element from each set. Both union by
// rank and path compression heuristics can be used or not used.
void unionSet(Node* element1, Node* element2, bool unionByRank, bool pathCompression)
{
	if (unionByRank)
	{
		link(findSet(element1, pathCompression), findSet(element2, pathCompression));
	}
	else
	{
		findSet(element1, pathCompression)->parent = findSet(element2, pathCompression);
	}
}

//link used if unionByRank is true
void link(Node* element1, Node* element2)
{
	if (element1->rank > element2->rank)
	{
		element2->parent = element1;
	}
	else
	{
		element1->parent = element2;

		if (element1->rank == element2->rank)
		{
			element2->rank++;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file