// Eman_Furrukh_21i1726
// Assignment #2 
// Question #2

#include <iostream>
using namespace std;

class Node {
public:
	const int data; //do not change this
	Node* next;
    Node* previous;
	Node(int d) : data(d) {
		this->next = NULL;
		this->previous = NULL;
	}
};

void insertionSort(Node*& head, Node*& tail) {
	//funcation only called of the list is unsorted
    if (head == NULL) 
        return;

    Node* ptr = head->next;
    while (ptr != NULL) {
        Node* ptr2 = ptr->previous;
        while (ptr2 != NULL && ptr2->data > ptr->data) {
            // swap nodes
            Node* temp = ptr2->previous;
            ptr2->previous = ptr;
            ptr->previous = temp;
            if (temp != NULL) 
                temp->next =ptr;

            temp = ptr->next;
            ptr->next = ptr2;
            ptr2->next = temp;

            if (temp != NULL) 
                temp->previous = ptr2;
            if (ptr2 == head)
                head = ptr;
            if (ptr == tail)
                tail = ptr2;
            // move ptr2 back one step
            ptr2 = ptr->previous;
        }
        // move ptr forward one step
        ptr = ptr->next;
    }
}

int input(Node*& head, Node*& tail, int no_of_elements) {
	//ask user for providing the number of items in the list. Then create n number of nodes
    cout << "Enter elements: " << endl;
    int n;
    for (int i = 0; i < no_of_elements; i++) {
        cin >> n;
        Node* temp = new Node(n);
        if (tail == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            temp->previous = tail;
            tail = temp;
        }
    }
    return no_of_elements;
}

bool isSorted(Node* head, Node* tail) {
	bool flag = true;
	//returns true if the list is sorted
    if (head == NULL || head == tail) 
        return flag;
    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->data > temp->next->data) 
            flag =false;
        temp = temp->next;
    }
    //return true;
	return flag;
}

bool binarySearch(Node* head, Node* tail, Node* mid, int search_number) {
    while (head != NULL && tail != NULL && head != tail->next) {
        mid = head;
        int count = 0;
        while (mid != NULL && mid != tail->next && count < 2) {
            if (mid->data == search_number) 
                return true;
            else if (mid->data < search_number) 
                mid = mid->next;
            else 
                mid = mid->previous;
            count++;
        }
        if (count == 2) {
            tail = mid->previous;
            head = mid->next;
        }
    }
    return false;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    Node* mid = NULL;
	int no_of_elements = 0;
	int search_number;

    cout << "Enter number of elements: ";
    cin >> no_of_elements;
    no_of_elements = input(head, tail, no_of_elements);
    if (!isSorted(head, tail)) 
        insertionSort(head, tail);

    cout << "Enter number: ";
    cin >> search_number;

    if (binarySearch(head,tail,mid,search_number) == true)
        cout << "Number found\n";
    else
        cout << "Number not found\n";
    
    return 0;
}
