#include <iostream>
#include <vector>

int main()
{
	//For each 𝑁 ∈ {10, 100, 1000, 10000}, perform the following 10 times: generate a random vector of
	//length 𝑁 where each entry of the vector is a random number in {0, 1, 2, … , 999} and record the wall
	//clock time required to sort the random vector using each of the sorts in parts (a)-(c). Use 10 buckets for
	//bucket sort.
	//For each sorting algorithm, compute the average wall clock time in milliseconds for each 𝑁. Which
	//algorithm is faster for small 𝑁? What about for large 𝑁? How do the wall clock times and growth rates
	//compare to the big O average time complexities? Submit your average wall clock times and answers
	//to the above questions in a separate file from your code (e.g. in a Word document)!
	//
	//The & denotes a parameter that is passed to a function by reference. This is required to sort a vector in place,
	//i.e. without creating a copy of the vector. You may wish to consult optional sections 16.28 and 16.29 of
	//your zyBook on passing by reference. You may assume that all entries of the vector are non-negative
	//integers!

	std::vector<int> numbers = { 10, 2, 78, 4, 45, 32, 7, 11 };

	std::cout << "Unsorted: ";
	for (int i : numbers)
	{
		std::cout << i << ' ';
	}

	/*void insertionSort(std::vector<int>& numbers);
	insertionSort(numbers);*/
	/*void bucketSort(std::vector<int>&numbers, int numBuckets);
	bucketSort(numbers, 5);*/
	void radixSort(std::vector<int>&numbers);
	radixSort(numbers);

	std::cout << std::endl << "Sorted: ";
	for (int i : numbers)
	{
		std::cout << i << ' ';
	}
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
	//Sorts the list by base - 10 radix sort


}