// Eman_Furrukh_21i1726
// Assignment #2 
// Question #1

#include <iostream>
using namespace std;

class student_Node {
public:
	string data;
	student_Node* next;
	student_Node(string data) {
		this->data = data;
		this->next = NULL;
	}
};
//The above portion cannot be changed

string* list_of_all_students(student_Node* head1, student_Node* head2, student_Node* head3) {
	string* result = new string[18];
    int i = 0;

    student_Node* temp = head1;
    while (temp != NULL) {
        result[i++] = temp->data;
        temp = temp->next;
    }
    temp = head2;
    while (temp != NULL) {
        result[i++] = temp->data;
        temp = temp->next;
    }
    temp = head3;
    while (temp != NULL) {
        result[i++] = temp->data;
        temp = temp->next;
    }
    return result;
}

string* list_common_student_society(student_Node* head1, student_Node* head2, student_Node* head3) {
    string* result = new string[6];
    int index = 0;

    student_Node* temp1 = head1;
    while (temp1 != NULL) {
        student_Node* temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                student_Node* temp3 = head3;
                while (temp3 != NULL) {
                    if (temp1->data == temp3->data) {
                        result[index++] = temp1->data;
                        break;
                    }
                    temp3 = temp3->next;
                }
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}

int main() {
    // names for people in FCG Society
    student_Node* FGC_List = new student_Node("Ali");
    FGC_List->next = new student_Node("Usman");
    FGC_List->next->next = new student_Node("Haider");
    FGC_List->next->next->next = new student_Node("Maryam");
    FGC_List->next->next->next->next = new student_Node("Masooma");
    FGC_List->next->next->next->next->next = new student_Node("Urooj");

    // names for people in FAS Society
    student_Node* FAS_List = new student_Node("Ashiq");
    FAS_List->next = new student_Node("Manika");
    FAS_List->next->next = new student_Node("Ali");
    FAS_List->next->next->next = new student_Node("Masooma");
    FAS_List->next->next->next->next = new student_Node("Akbar");
    FAS_List->next->next->next->next->next = new student_Node("Urooj");

    // names for people in FDS Society
    student_Node* FDS_List = new student_Node("Masooma");
    FDS_List->next = new student_Node("Bilal");
    FDS_List->next->next = new student_Node("Amna");
    FDS_List->next->next->next = new student_Node("Madiha");
    FDS_List->next->next->next->next = new student_Node("Rohail");
    FDS_List->next->next->next->next->next = new student_Node("Urooj");

    // displaying all the society members names
    string* all_students = list_of_all_students(FGC_List, FAS_List, FDS_List);
    cout << "List_of_all_student (string array) = ";
    for (int i = 0; i < 18; i++) 
        cout << all_students[i] << " ";
    cout << endl;

    // displaying all the common society members
    string* common_students = list_common_student_society(FGC_List, FAS_List, FDS_List);
    cout << "List_of_common_student (string array) = ";
    for (int i = 0; i < 2; i++) 
        cout << common_students[i] << " ";
    cout << endl;

    return 0;
}
