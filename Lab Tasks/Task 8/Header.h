#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	Node* next;
	int data;
	Node() {
		next = NULL;
		data = 0;
	}
	void setNext(Node* n) { next = n; }
	void setData(int d) { data = d; }
	Node* getNext() { return next; }
	int getData() { return data; }
};

template <class T>
class Queue {
private:
	Node* front; // pointer to the first node
	Node* rear; // pointer to the last node
	int numItems; // Number of nodes in the linked list
public:
	Queue() {
		front = NULL;
		rear = NULL;
		numItems = 0;
	}
	~Queue(void) {
		makeNull();
	}
	void setFront(Node* f) { front = f; }
	void setRear(Node* r) { rear = r; }
	void setNumItems(int n) { numItems = n; }
	Node* getFront() { return front; }
	Node* getRear() { return rear; }
	int getNumItems() { return numItems; }
	T Front() { return front->data; }
	void enqueue(int num) {
		Node* newNode;
		newNode = new Node;
		newNode->data = num;
		newNode->next = NULL;
		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		numItems++;
	}
	int dequeue() {
		Node* temp;
		int num = -1;
		if (isEmpty())
			cout << "The queue is empty.\n";
		else {
			num = front->data;
			temp = front->next;
			delete front;
			front = temp;
			numItems--;
			if (!numItems) 
				rear = NULL;
		}
		return num;
	}
	bool isEmpty() {
		if (numItems)
			return false;
		else
			return true;
	}
	void makeNull() {
		while (!isEmpty()) {
			dequeue();
		}
	}
	//void roundRobin(Queue q, int t);
};

void roundRobin(Queue q, int t)
{
	int z = 0;
	while (q.numItems != 0) {
		if (q.front->data <= t) {
			q.print();
			q.front = q.front->next;
			z++;
			q.numItems--;
		}
		else {
			q.enqueue(q.front->data - t);
			q.front = q.front->next;
			z++;
			q.numItems--;
		}
	}
}