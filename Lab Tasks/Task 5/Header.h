#pragma once
#include <iostream>
using namespace std;

template<class T>
class List {
	T* ptr;
	int size;
	int cIndex;
public:
	//parameterised constructor
	List(int s) {
		size = s;
		cIndex = 0;
		ptr = new T[size];
		for (int i = 0; i < size; i++)
			ptr[i] = 0;
	}
	//a function that returns the value at given index
	int values(int index) {
		return ptr[index];
	}
	//insert an item and incremenet only if array is not full
	bool insert(T item) {
		bool flag = false;
		if (cIndex < size)
		{
			ptr[cIndex] = item;
			cIndex++;
			flag = true;
		}
		return flag;
	}
	//insert item at specific index
	bool insertAt(T item, int index) {
		bool flag = false;
		if (cIndex < size)
		{
			for (int i = 0; i < cIndex; i++)
			{
				if (i == index)
				{
					for(int j = size; j < i; --j)
						ptr[j + 1] = ptr[j];
					ptr[i] = item;
					cIndex++;
					flag = true;
				}
			}
		}
		return flag;
	}
	//insert item after
	void insertAfter(int itemTobeInserted, int item) {
		ptr[item + 1] = itemTobeInserted;
	}
	//insert item before
	void insertBefore(int itemTobeInserted, int item) {
		ptr[item - 1] = itemTobeInterested;
	}
	//check if array is empty
	bool isEmpty() {
		bool flag = true;
		for (int i = 0; i < 5; i++)
		{
			if (ptr[i] != 0)
				flag = false;
		}
		return flag;
	}
	//check if array is full
	bool isFull() {
		return cIndex == size;
	}
	//remove selected item
	void remove(T item) {
		for (int i = 0; i < size + 1; i++)
		{
			if (ptr[i] == item)
			{
				ptr[i] = 0;
				cIndex--;
				for (int j = i; j < cIndex; j++)
					ptr[j] = ptr[j + 1];
			}
		}
	}
	//remove item before
	void removeBefore(T item) {
		for (int i = 0; i < size + 1; i++)
		{
			if (ptr[i] == item)
			{
				ptr[i - 1] = 0;
				cIndex--;
				for (int j = i - 1; j < size; j++)
					ptr[j] = ptr[j + 1];
				ptr[cIndex] = 0;
			}
		}
	}
	//remove item after
	/**void removeAfter(T item) {
		
	}*/

	//returns index of item found
	int search(T item) {
		for (int i = 0; i < size; i++) {
			if (ptr[i] == item)
				return i;
			else
				return 0;
		}

	}
	//displays List values
	void print() {
		cout << "List Items are:\n";
		for (int i = 0; i < size; i++)
		{
			cout << ptr[i] << " ";
		}
		cout << endl;
	}
	bool operator==(List L) {
		bool flag = false;
		for (int i = 0; i < 5; i++) {
			if (this->ptr[i] == L.ptr[i])
				flag = true;
		}
		return flag;
	}
	//display List values in reverse
	int reverse() {
		int j = 5;
		for (int i = 0; i <= j ; i++) {
			ptr[i] = ptr[j];
			j--;
		}
		return *ptr;
	}
};