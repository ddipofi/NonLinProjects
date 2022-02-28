#include "HybridList.h"
#include <iostream>

int main()
{
	HybridList list = HybridList();
	list.push_back(5);
	list.push_back(6);
	list.push_back(6);
	list.push_back(6);
	list.push_back(6);
	list.push_back(6);
	list.push_back(6);
	list.push_back(6);
	list.insert(3, 4);

	std::cout << "hi";

	return 0;
}