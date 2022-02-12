#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"CharacterFrequencies.h"

CharacterFrequencies tempCharFreqs;

//int main()
//{
//	string line = "Twinkle twinkle little star, how I wonder what you are.";
//	CharacterFrequencies charFreqs(line);
//
//	cout << line << endl;
//	charFreqs.printFrequencies();
//	charFreqs.readString(line);
//	charFreqs.printFrequencies();
//
//	return 0;
//}

CharacterFrequencies::CharacterFrequencies()
{

}

CharacterFrequencies::CharacterFrequencies(string line)
{
	readString(line);
}

void CharacterFrequencies::readString(string line)
{
	for (int i = 0; i < line.length(); i++)
	{
		bool added = false;

		for (int j = 0; j < tempCharFreqs.frequencies.size(); j++)
		{
			if (tempCharFreqs.frequencies.at(j).first == line[i])
			{
				tempCharFreqs.frequencies.at(j).second++;
				added = true;
				break;
			}
		}

		if (!added)
		{
			tempCharFreqs.frequencies.push_back(make_pair(line[i], 1));
		}
	}
}

void CharacterFrequencies::reset()
{
	for (int i = 0; i < tempCharFreqs.frequencies.size(); i++)
	{
		tempCharFreqs.frequencies.at(i).second = 0;
	}
}

int CharacterFrequencies::getFrequency(char c)
{
	for (int i = 0; i < tempCharFreqs.frequencies.size(); i++)
	{
		if (tempCharFreqs.frequencies.at(i).first == c)
		{
			return tempCharFreqs.frequencies.at(i).second;
		}
	}
}

void CharacterFrequencies::printFrequencies()
{
	for (int i = 0; i < tempCharFreqs.frequencies.size(); i++)
	{
		if (tempCharFreqs.frequencies.at(i).second != 0)
		{
			cout << tempCharFreqs.frequencies.at(i).first << ": " << tempCharFreqs.frequencies.at(i).second << endl;
		}
	}
}

