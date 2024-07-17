#pragma once
#include <iostream>
using namespace std;

template <class N>
class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = nullptr;
    }

    // Parameterized constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }

    // Getter for data
    int get_data() {
        return data;
    }

    // Setter for data
    void set_data(int val) {
        data = val;
    }

    // Getter for next pointer
    Node* get_next() {
        return next;
    }

    // Setter for next pointer
    void set_next(Node* next_node) {
        next = next_node;
    }
};

template <class T>
class SLinkedList {
private:
    Node* head;
public:
    // default constructor
    SLinkedList() {
        head = NULL;
    }

    // Insert function to insert data item at the end of the LL
    void insert(int data) {
        Node* new_node = new Node(data);
        if (head == NULL) {
            head = new_node;
        }
        else {
            Node* curr = head;
            while (curr->get_next() != NULL) {
                curr = curr->get_next();
            }
            curr->set_next(new_node);
        }
    }

    // Insert to head function to insert data element at the start of your LL
    void insertToHead(int data) {
        Node* new_node = new Node(data);
        new_node->set_next(head);
        head = new_node;
    }

    // isEmpty function to check if there is no data element in the LL
    bool isEmpty() {
        return head == NULL;
    }

    // Search function to search for any element provided by user
    bool search(int data) {
        Node* curr = head;
        while (curr != NULL) {
            if (curr->get_data() == data) {
                return true;
            }
            curr = curr->get_next();
        }
        return false;
    }

    // Update function to update/replace one data element with another
    bool update(int oldData, int newData) {
        Node* curr = head;
        while (curr != NULL) {
            if (curr->get_data() == oldData) {
                curr->set_data(newData);
                return true;
            }
            curr = curr->get_next();
        }
        return false;
    }

    // Insert at index function to insert data at a specific index in the LL
    bool insertAtIndex(int index, int data) {
        Node* new_node = new Node(data);
        int count = 0;
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL && count < index) {
            prev = curr;
            curr = curr->get_next();
            count++;
        }
        if (count == index) {
            new_node->set_next(curr);
            if (prev == NULL) {
                head = new_node;
            }
            else {
                prev->set_next(new_node);
            }
            return true;
        }
        return false;
    }

    // Delete function to delete the specified data element
    bool remove(int data) {
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL) {
            if (curr->get_data() == data) {
                if (prev == NULL) {
                    head = curr->get_next();
                }
                else {
                    prev->set_next(curr->get_next());
                }
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->get_next();
        }
        return false;
    }

    // Function to print the data of LL
    void print() {
        Node* curr = head;
        while (curr != NULL) {
            std::cout << curr->get_data() << " ";
            curr = curr->get_next();
        }
        std::cout << std::endl;
    }

    void mergeLists(LinkedList& l2) {
        Node* temp1 = head;
        Node* temp2 = l2.head;
        Node* prev = nullptr;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp2->data < temp1->data) {
                if (prev != nullptr) {
                    prev->next = temp2;
                }
                else {
                    head = temp2;
                }
                Node* next = temp2->next;
                temp2->next = temp1;
                prev = temp2;
                temp2 = next;
            }
            else {
                prev = temp1;
                temp1 = temp1->next;
            }
        }
        if (temp2 != nullptr) {
            prev->next = temp2;
        }
    }
};

