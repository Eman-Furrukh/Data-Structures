#pragma once
#include <iostream>
using namespace std;

									///TASK 3
bool superString(string str)
{
	char* value = &str[0];
	int res = ((*value - 'A') * -1 + 26);
	int count = 0;
	while (*value != '\0') {
		value++;
		count++;
	}
	bool check = true;
	for (int i = 0; i < count - 1; i++) {
		char* value = &str[i];
		int res = ((*value - 'A') * -1 + 26);
		int c = 0;
		while (*value != '\0') {
			if (str[i] == *value)
				c++;
			value++;
		}
		if (res != c)
			return false;
	}
	return check;
}

									///TASK 4
int subPalindrome(string str)
{
	int count = 0;
	char* value = &str[0];
	while (*value != '\0') {
		count++;
		value++;
	}
	int x = 0;
	for (int i = 0; i < count; i++) {
		value = &str[i];
		while (*value != '\0') {
			if (*value == str[i]) {
				bool check = false;
				bool oddoreven;
				if (i % 2 == 0)
					oddoreven = true;
				else
					oddoreven = false;

				int comparisons = i / 2;
				for (int j = 0; j < 2; j++) {
					if (str[i] == str[comparisons])
						x++;
				}
			}
			value++;
		}
	}
	return count;
}

								 ///TASK 5
int* toIntArray(string value) {
	int size = value.size();
	int* arr = new int[10];

	for (int i = 0; i < size; i++) {
		if (value.at(i) == '1') 
			arr[i] = 1;
		else if (value.at(i) == '0') 
			arr[i] = 0;
		else if (value.at(i) == '2') 
			arr[i] = 2;
		else if (value.at(i) == '3') 
			arr[i] = 3;
		else if (value.at(i) == '4') 
			arr[i] = 4;
		else if (value.at(i) == '5') 
			arr[i] = 5;
		else if (value.at(i) == '6') 
			arr[i] = 6;
		else if (value.at(i) == '7') 
			arr[i] = 7;
		else if (value.at(i) == '8') 
			arr[i] = 8;
		else if (value.at(i) == '9') 
			arr[i] = 9;
	}
	return arr;
}

int* addTwoArray(string value1, string value2) {
	int size = value1.size();
	int* arr = new int[10];

	for (int i = 0; i < size; i++) {
		if (value1.at(i) == '1') 
			arr[i] = 1;
		else if (value1.at(i) == '0') 
			arr[i] = 0;		
		else if (value1.at(i) == '2') 
			arr[i] = 2;		
		else if (value1.at(i) == '3') 
			arr[i] = 3;		
		else if (value1.at(i) == '4') 
			arr[i] = 4;		
		else if (value1.at(i) == '5') 
			arr[i] = 5;		
		else if (value1.at(i) == '6') 
			arr[i] = 6;		
		else if (value1.at(i) == '7') 
			arr[i] = 7;		
		else if (value1.at(i) == '8') 
			arr[i] = 8;		
		else if (value1.at(i) == '9') 
			arr[i] = 9;
	}
	for (int i = 0; i < size; i++)
		arr[i] += arr[i];
	return arr;
}

int* subTwoArray(string value1, string value2) {
	int size = value1.size();
	int* arr = new int[10];

	for (int i = 0; i < size; i++) {
		if (value1.at(i) == '1') 
			arr[i] = 1;
		else if (value1.at(i) == '0') 
			arr[i] = 0;
		else if (value1.at(i) == '2') 
			arr[i] = 2;
		else if (value1.at(i) == '3') 
			arr[i] = 3;
		else if (value1.at(i) == '4') 
			arr[i] = 4;
		else if (value1.at(i) == '5') 
			arr[i] = 5;
		else if (value1.at(i) == '6') 
			arr[i] = 6;
		else if (value1.at(i) == '7') 
			arr[i] = 7;
		else if (value1.at(i) == '8') 
			arr[i] = 8;
		else if (value1.at(i) == '9') 
			arr[i] = 9;
	}
	for (int i = 0; i < size; i++) 
		arr[i] -= arr[i];
	return arr;
}