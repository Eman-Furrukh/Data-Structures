#pragma once
#include <iostream>
#include <stack>
#include <string>
using namespace std;

//	Question #1

template <typename T>
struct node {
	int val;
	node<T>* next;
	node() {
		val = 0;
		next = NULL;
	}
};

template <class S>
class Stack {
	node<S>* top;
	int size;
public:
	//constructor
	Stack(int ignored = 0) {
		//*top->val = 0;
		size = 0;
	}
	//destructor
	~Stack() {
		delete[] top;
	}

	//function to push operator onto stack
	void push(const int DataItem) {
		node<S>* newptr;
		newptr = new node<S>;
		newptr->val = DataItem;
		newptr->next = top;
		top = newptr;
		size++;
	}

	//function to pop operator from stack
	void pop() {
		node<S>* tempptr;
		int value;
		if (isEmpty())
			cout << "underflow error";
		else
		{
			tempptr = top;
			value = top->val;
			top = top->next;
			delete tempptr;
			size--;
		}
	}

	//function to return element at the top of stack
	node<S>* Peek() {
		return top;
	}

	//function to remove all the elements from a stack.
	void clear() {
		top = NULL;
		~top();
	}

	//function to check whether stack is empty
	bool isEmpty() {
		if (top->next == NULL)
			return true;
		else
			return false;
	}
	//function to return size of stack
	S sizeofstack() {
		return this-> size;
	}
};

//	Question #2

bool validate(const std::string& code) {
	std::stack<char> brackets;
	for (const char c : code) {
		switch (c) {
		case '(':
		case '{':
		case '[':
			brackets.push(c);
			break;
		case ')':
			if (brackets.empty() || brackets.top() != '(')
				return false;
			brackets.pop();
			break;
		case '}':
			if (brackets.empty() || brackets.top() != '{')
				return false;
			brackets.pop();
			break;
		case ']':
			if (brackets.empty() || brackets.top() != '[')
				return false;
			brackets.pop();
			break;
		default:
			break;
		}
	}
	return brackets.empty();
}

//	Question #3

bool isLetter(char c) {
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isSpace(char c) {
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}
bool checkPal(char* str) {
	int length = strlen(str);
	for (int i = 0, j = length - 1; i < j; i++, j--) {
		while (i < j && !isLetter(str[i])) 
			i++;
		while (i < j && !isLetter(str[j])) 
			j--;
		if (tolower(str[i]) != tolower(str[j])) 
			return false;
	}
	return true;
}