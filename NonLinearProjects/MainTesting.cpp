#include "HybridList.h"
#include <iostream>

int main()
{
	HybridList list = HybridList();
	
	list.push_back(0);

	for (int i = 1; i < 12; i++)
	{
		list.insert(0, i);
	}

	std::cout << list.at(3);
	std::cout << list.at(10);

	/*for (int i = 0; i < 12; i++)
	{
		list.pop_back();
	}*/

	//list.erase(3);

	//std::cout << list.at(3);

	return 0;
}