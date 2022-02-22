#include "BoundedArray.h"
#include <iostream>

int main()
{
	BoundedArray boundedArray(7, 10);

	std::cout << boundedArray[6];

	return 0;
}