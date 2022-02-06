#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"CharacterFrequencies.h"

int main()
{
	std::string fileName = "input.txt";
	std::string fileString;
	std::ifstream fileTxt;

	fileTxt.open(fileName);

	if (!fileTxt.is_open())
	{
		std::cout << "The input file " << fileName << " could not be opened.";
		return EXIT_FAILURE;
	}

	while (!fileTxt.eof())
	{
		getline(fileTxt, fileString);
	}

	fileTxt.close();

	int count = 0;
	char userChar;
	std::vector<int> charIndices;

	std::cout << "Enter the character to search for: ";
	std::cin >> userChar;

	for (int i = 0; i < fileString.length(); i++)
	{
		if (fileString[i] == userChar)
		{
			count++;
			charIndices.push_back(i);
		}
	}

	std::cout << "The number of occurences of the character " << userChar << " is " << count << std::endl;

	if (count != 0)
	{
		std::cout << "The indices of the character positions are ";

		for (int i : charIndices)
		{
			std::cout << i << " ";
		}
	}

	return 0;
}