#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

void insertionSort(std::vector<int>& numbers);
void bucketSort(std::vector<int>& numbers, int numBuckets);
void radixSort(std::vector<int>& numbers);
std::vector<int> generateRandomVector(int listSize);

int main()
{
	//used microseconds and converted to milliseconds in word doc, because milliseconds were 0

	std::vector<int> iList;
	std::vector<int> bList;
	std::vector<int> rList;
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = start;
	auto totalTimeI = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	auto totalTimeB = totalTimeI;
	auto totalTimeR = totalTimeI;

	for (int i = 10; i < 10001; i *= 10)
	{
		for (int j = 0; j < 10; j++)
		{
			iList = generateRandomVector(i);
			bList = iList;
			rList = iList;

			start = std::chrono::high_resolution_clock::now();
			insertionSort(iList);
			stop = std::chrono::high_resolution_clock::now();
			totalTimeI += std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

			start = std::chrono::high_resolution_clock::now();
			bucketSort(bList, 10);
			stop = std::chrono::high_resolution_clock::now();
			totalTimeB += std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

			start = std::chrono::high_resolution_clock::now();
			radixSort(rList);
			stop = std::chrono::high_resolution_clock::now();
			totalTimeR += std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		}

		std::cout << "Avg wall clock time for insertionSort() when N = " << i << ": " << totalTimeI.count() / 10 << std::endl;
		std::cout << "Avg wall clock time for bucketSort() when N = " << i << ": " << totalTimeB.count() / 10 << std::endl;
		std::cout << "Avg wall clock time for radixSort() when N = " << i << ": " << totalTimeR.count() / 10 << std::endl;

		start = std::chrono::high_resolution_clock::now();
		stop = start;
		totalTimeI = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		totalTimeB = totalTimeI;
		totalTimeR = totalTimeI;
	}

	return 0;
}

void insertionSort(std::vector<int>& numbers)
{
	for (int i = 1; i < numbers.size(); i++)
	{
		int j = i;

		while (j > 0 && numbers[j] < numbers[j-1])
		{
			int temp = numbers[j];
			numbers[j] = numbers[j-1];
			numbers[j-1] = temp;
			j--;
		}
	}
}

void bucketSort(std::vector<int>& numbers, int numBuckets)
{
	std::vector<std::vector<int>> buckets(numBuckets);

	int maxValue = numbers[0];
	for (int i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] > maxValue)
		{
			maxValue = numbers[i];
		}
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		int bucketIndex = floor((numbers[i] * numBuckets) / (maxValue + 1));
		buckets[bucketIndex].push_back(numbers[i]);
	}

	numbers.clear();

	for (int i = 0; i < numBuckets; i++)
	{
		insertionSort(buckets[i]);
		numbers.insert(numbers.end(), buckets[i].begin(), buckets[i].end());
	}
}

void radixSort(std::vector<int>& numbers)
{
	int radixGetMaxLength(std::vector<int>&numbers);
	std::vector<std::vector<int>> buckets(10);
	int copyBackIndex = 0;
	int maxDigits = radixGetMaxLength(numbers);
	int pow10 = 1;

	for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++)
	{
		for (int i = 0; i < 10; i++)
		{
			buckets[i].clear();
		}

		for (int i = 0; i < numbers.size(); i++)
		{
			int num = numbers[i];
			int bucketIndex = (abs(num) / pow10) % 10;
			buckets[bucketIndex].push_back(num);
		}

		copyBackIndex = 0;

		for (int i = 0; i < 10; i++)
		{
			std::vector<int> bucket = buckets[i];

			for (int j = 0; j < bucket.size(); j ++)
			{
				numbers[copyBackIndex] = bucket[j];
				copyBackIndex++;
			}

			bucket.clear();
		}

		pow10 *= 10;
	}

	std::vector<int> negatives;
	std::vector<int> nonNegatives;

	for (int num : numbers)
	{
		if (num < 0)
		{
			negatives.push_back(num);
		}
		else
		{
			nonNegatives.push_back(num);
		}
	}

	copyBackIndex = 0;

	for (int i = negatives.size() - 1; i >= 0; i--)
	{
		numbers[copyBackIndex] = negatives[i];
		copyBackIndex++;
	}

	for (int i = 0; i < nonNegatives.size(); i++)
	{
		numbers[copyBackIndex] = nonNegatives[i];
		copyBackIndex++;
	}
}

int radixGetMaxLength(std::vector<int>& numbers)
{
	int radixGetLength(int value);

	int maxDigits = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		int digitCount = radixGetLength(numbers[i]);

		if (digitCount > maxDigits)
		{
			maxDigits = digitCount;
		}
	}

	return maxDigits;
}

int radixGetLength(int value)
{
	if (value == 0)
	{
		return 1;
	}

	int digits = 0;

	while (value != 0)
	{
		digits++;
		value /= 10;
	}

	return digits;
}

std::vector<int> generateRandomVector(int listSize) {
	std::vector<int> randomList(listSize);

	for (int i = 0; i < listSize; i++)
		randomList.at(i) = rand() % 1000;

	return randomList;
}