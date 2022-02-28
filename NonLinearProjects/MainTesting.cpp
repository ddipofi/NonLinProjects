#include "HybridList.h"
#include <iostream>

int main()
{
	HybridList list = HybridList();
	
	for (int i = 0; i < 9; i++)
	{
		list.push_back(i);
	}

	//list.erase(3);

	std::cout << list.at(3);

	return 0;
}