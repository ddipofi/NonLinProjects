#include <iostream>
#include <string>
#include <stdexcept>
#include "HybridList.h"
using namespace std;

HybridList::HybridList() {}

HybridList::HybridList(int blockSize) {
	if (blockSize <= 0)
		throw out_of_range("Invalid block size " + to_string(blockSize));
	this->blockSize = blockSize;
}

HybridList::~HybridList() {
	clear();
}

int HybridList::size() const {
	return numElements;
}

int HybridList::capacity() const {
	return numBlocks * blockSize;
}

int HybridList::block_size() const {
	return blockSize;
}

HybridListNode* HybridList::front() const {
	return head;
}

HybridListNode* HybridList::back() const {
	return tail;
}

double& HybridList::at(int index) const {
	HybridListNode* curNode = head;
	int elementsSearched = 0;

	if (index < 0 || index >= numElements)
		throw out_of_range("Invalid index " + to_string(index));

	// Iterate through all blocks to identify block containing the index
	while (curNode != nullptr) {
		if (index < elementsSearched + curNode->size()) {
			// Element is in this block so just return the correct element from
			// this block
			return curNode->at(index - elementsSearched);
		}
		// Element is not in this block so add the number of elements in the
		// block to the number of elements searched
		elementsSearched += curNode->size();
		curNode = curNode->next;
	}

	// Iterator went beyond last block so something went horribly wrong
	abort();
}

void HybridList::push_back(double value) {
	if (numBlocks == 0) {
		// Hybrid list is empty so creating a new node that will be both the head
		// and tail and append the element to it
		HybridListNode* newTail = new HybridListNode(blockSize);
		newTail->push_back(value);
		tail = newTail;
		head = newTail;
		numBlocks = 1;
	}
	else if (tail->size() == blockSize) {
		// Tail node is full so create a new tail node and copy the back half of
		// the old tail node to the new tail node
		HybridListNode* newTail = new HybridListNode(blockSize);

		// Copy just under half of elements from old tail to new tail
		for (int i = blockSize / 2 + 1; i < blockSize; i++)
			newTail->push_back(tail->at(i));
		tail->resize(blockSize / 2 + 1);
		//cout << tail->size() << endl;
		// Append new item to new tail
		newTail->push_back(value);
		tail->next = newTail;
		//cout << newTail->size() << endl;
		//cout << "Tail: " << tail << endl;
		//cout << "New tail: " << newTail << endl;
		tail = newTail;
		numBlocks++;
	}
	else
		tail->push_back(value);	// Tail isn't full so just append to tail

	numElements++;
}

void HybridList::pop_back()
{
	if (numBlocks == 0)
	{
		throw out_of_range("Array is empty");
	}
	else
	{
		tail->pop_back();
		numElements--;

		if (tail->size() == 0)
		{
			if (numBlocks == 1)
			{
				HybridListNode* curNode = head;
				delete curNode;
				head = tail = nullptr;
			}
			else
			{
				HybridListNode* curNode = head, * prevNode = nullptr;

				while (curNode->next != nullptr) {
					prevNode = curNode;
					curNode = curNode->next;
				}

				tail = prevNode;
				delete curNode;
			}

			numBlocks--;
		}
	}
}

void HybridList::insert(int index, double value)
{
	if (index < 0 || index >= numElements)
	{
		throw out_of_range("Invalid index " + to_string(index));
	}
	else
	{
		HybridListNode* curNode = head;
		int eNum = curNode->size();

		while ((index - 1 > eNum))
		{
			curNode = curNode->next;
			eNum += curNode->size();
		}

		if (curNode->size() == blockSize)
		{
			HybridListNode* newNode = new HybridListNode(blockSize);
			eNum -= curNode->size();

			for (int i = blockSize / 2 + 1; i < blockSize; i++)
			{
				newNode->push_back(curNode->at(i));
			}

			curNode->resize(blockSize / 2 + 1);
			numBlocks++;
			eNum += curNode->size();

			if (index - 1 > eNum)
			{
				curNode = newNode;
				eNum += curNode->size();
			}
		}

		int insertIndex = curNode->size() - 1;

		for (eNum; index < eNum - 1; eNum--)
		{
			insertIndex--;
		}

		curNode->insert(insertIndex, value);
		curNode->resize(curNode->size() + 1);
		numElements++;
	}
}

void HybridList::erase(int index)
{
	if (index < 0 || index >= numElements)
	{
		throw out_of_range("Invalid index " + to_string(index));
	}
	else
	{
		HybridListNode* curNode = head;
		int eNum = curNode->size();

		while ((index - 1 > eNum))
		{
			curNode = curNode->next;
			eNum += curNode->size();
		}



		//change to remove
		int eraseIndex = curNode->size() - 1;

		for (eNum; index < eNum - 1; eNum--)
		{
			eraseIndex--;
		}

		curNode->erase(eraseIndex);
		curNode->resize(curNode->size() - 1);

		//if its empty after removing, delete node
		if (curNode->size() == 0)
		{
			if (numBlocks == 1)
			{
				HybridListNode* curNode = head;
				delete curNode;
				head = tail = nullptr;
			}
			else
			{
				HybridListNode* curNode = head, * prevNode = nullptr;

				while (curNode->next != nullptr) {
					prevNode = curNode;
					curNode = curNode->next;
				}

				tail = prevNode;
				delete curNode;
			}

			numBlocks--;
		}

		numElements--;
	}
}

void HybridList::clear() {
	HybridListNode* curNode = head, * nextNode = nullptr;
	// Iterate through each node starting from the head and delete it
	while (curNode != nullptr) {
		nextNode = curNode->next;
		delete curNode;
		curNode = nextNode;
	}
	head = tail = nullptr;
	numElements = numBlocks = 0;
}