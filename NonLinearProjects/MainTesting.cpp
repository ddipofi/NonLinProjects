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
	list.push_back(6);
	list.push_back(6);
	list.push_back(6);
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();

	std::cout << "hi";

	return 0;
}