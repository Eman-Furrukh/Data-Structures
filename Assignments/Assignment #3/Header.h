// Data Structures
// Assignment #3
// Eman Furrukh
// 21i-1726

#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

///
/// Question2, Part_A_1
/// 
class DoubleLinkedList {
private:
    struct Node {
        string data;
        Node* prev;
        Node* next;
        Node(string data) : data(data), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoubleLinkedList() {
        while (!is_empty()) {
            pop();
        }
    }
    bool is_empty() {
        return size == 0;
    }
    int get_size() {
        return size;
    }
    void push(string data) {
        Node* new_node = new Node(data);
        if (is_empty()) {
            head = new_node;
            tail = new_node;
        }
        else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }
    string pop() {
        if (is_empty()) {
            return "empty";
        }
        Node* node_to_remove = tail;
        string data = node_to_remove->data;
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = node_to_remove->prev;
            tail->next = nullptr;
        }
        delete node_to_remove;
        size--;
        return data;
    }
    string top() {
        if (is_empty()) {
           return "empty";
        }
        return tail->data;
    }
};

int infix_to_postfix_A(string infix, char* output_stack, DoubleLinkedList& operator_stack) {
    int pos = 0; // Position to insert into output_stack
    string temp; // Temporarily stores a single operator
    for (char c : infix) {
        switch (c) {
            case '(': {
                operator_stack.push("(");
                break;
            }
            case ')': {
                while (!operator_stack.is_empty() && operator_stack.pop() != "(") {
                    output_stack[pos++] = temp[0];
                }
                break;
            }
            case '+':
            case '-':
            case '*':
            case '%': {
                while (!operator_stack.is_empty() && operator_stack.pop() != "(") {
                    output_stack[pos++] = temp[0];
                }
                temp = c;
                operator_stack.push(temp);
                break;
            }
            case '/': {
                while (!operator_stack.is_empty() && operator_stack.pop() != "(" && operator_stack.pop() != "*" && operator_stack.pop() != "%") {
                    output_stack[pos++] = temp[0];
                }
                temp = c;
                operator_stack.push(temp);
                break;
            }
            case '^': {
                while (!operator_stack.is_empty() && operator_stack.pop() != "(" && operator_stack.pop() != "*" && operator_stack.pop() != "%" && operator_stack.pop() != "+" && operator_stack.pop() != "-") {
                    output_stack[pos++] = temp[0];
                }
                temp = c;
                operator_stack.push(temp);
                break;
            }
            case 'a':
            case 'A':
            case 'b':
            case 'B':
            case 'c':
            case 'C':
            case 'd':
            case 'D':
            case 'e':
            case 'E':
            case 'f':
            case 'F':
            case 'g':
            case 'G':
            case 'h':
            case 'H': {
                output_stack[pos++] = c;
                break;
            }
            default: {
                break;
            }
        }
    }
    while (!operator_stack.is_empty() && operator_stack.pop() != "(") {
        output_stack[pos++] = temp[0];
    }
    return pos;
}

///
/// Question2, Part_A_2
/// 
bool is_operandA2(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool is_operatorA2(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedenceA2(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '^') {
        return 3;
    }
    else {
        return 0;
    }
}
    
string infix_to_postfixA2(const std::string& infix) {
    std::string postfix;
    std::stack<char> operator_stack;

    for (const char& c : infix) {
        if (is_operandA2(c)) {
            postfix += c;
        }
        else if (c == '(') {
            operator_stack.push(c);
        }
        else if (c == ')') {
            while (!operator_stack.empty() && operator_stack.top() != '(') {
                postfix += operator_stack.top();
                operator_stack.pop();
            }
            if (!operator_stack.empty() && operator_stack.top() == '(') {
                operator_stack.pop();
            }
            else {
                // Mismatched parentheses
                return "";
            }
        }
        else {
            while (!operator_stack.empty() && precedenceA2(c) <= precedenceA2(operator_stack.top())) {
                postfix += operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push(c);
        }
    }

    while (!operator_stack.empty()) {
        if (operator_stack.top() == '(' || operator_stack.top() == ')') {
            // Mismatched parentheses
            return "";
        }
        postfix += operator_stack.top();
        operator_stack.pop();
    }
    return postfix;
}


///
/// Question2, Part_A_3
/// 
bool is_operand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedenceA3(char c) {
    if (c == '+' || c == '-') {
        return 2;
    }
    else if (c == '*' || c == '/') {
        return 3;
    }
    else if (c == '^') {
        return 1;
    }
    else {
        return 0;
    }
}

string infix_to_postfix_A3(const std::string& infix) {
    std::string postfix;
    std::stack<char> operator_stack;

    for (const char& c : infix) {
        if (is_operand(c)) {
            postfix += c;
        }
        else if (c == '(') {
            operator_stack.push(c);
        }
        else if (c == ')') {
            while (!operator_stack.empty() && operator_stack.top() != '(') {
                postfix += operator_stack.top();
                operator_stack.pop();
            }
            if (!operator_stack.empty() && operator_stack.top() == '(') {
                operator_stack.pop();
            }
            else {
                // Mismatched parentheses
                return "";
            }
        }
        else {
            while (!operator_stack.empty() && precedenceA3(c) <= precedenceA3(operator_stack.top())) {
                postfix += operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push(c);
        }
    }

    while (!operator_stack.empty()) {
        if (operator_stack.top() == '(' || operator_stack.top() == ')') {
            // Mismatched parentheses
            return "";
        }
        postfix += operator_stack.top();
        operator_stack.pop();
    }
    return postfix;
}

///
/// Question2, Part_A_4
/// 
// Function to get the precedence of an operator
bool is_operandA4(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool is_operatorA4(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || (c == 'A' || c == 'a');
}

bool is_abc_operator(char c) {
    return c == 'A' || c == 'a';
}

int precedenceA4(char c) {
    if (is_abc_operator(c)) {
        return 4;
    }
    else if (c == '+' || c == '-') {
        return 2;
    }
    else if (c == '*' || c == '/') {
        return 3;
    }
    else if (c == '^') {
        return 1;
    }
    else {
        return 0;
    }
}

string infix_to_postfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operator_stack;

    for (const char& c : infix) {
        if (is_operandA4(c)) {
            postfix += c;
        }
        else if (c == '(') {
            operator_stack.push(c);
        }
        else if (c == ')') {
            while (!operator_stack.empty() && operator_stack.top() != '(') {
                postfix += operator_stack.top();
                operator_stack.pop();
            }
            if (!operator_stack.empty() && operator_stack.top() == '(') {
                operator_stack.pop();
            }
            else {
                return "";
            }
        }
        else {
            while (!operator_stack.empty() && precedenceA4(c) <= precedenceA4(operator_stack.top())) {
                postfix += operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push(c);
        }
    }

    while (!operator_stack.empty()) {
        if (operator_stack.top() == '(' || operator_stack.top() == ')') {
            // Mismatched parentheses
            return "";
        }
        postfix += operator_stack.top();
        operator_stack.pop();
    }
    return postfix;
}

///
/// Question2, Part_A_5
/// 
// Returns true if the given character is an operator
bool is_operatorA5(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'A' || c == 'B' || c == 'C';
}

// Returns the precedence of the given operator
int precedenceA5(char op) {
    if (op == 'A' || op == 'a' || op == 'B' || op == 'b' || op == 'C' || op == 'c') {
        return 3; // Highest precedence
    }
    if (op == '^') {
        return 2; // Second highest precedence
    }
    if (op == '*' || op == '/') {
        return 1; // Third highest precedence
    }
    if (op == '+' || op == '-') {
        return 0; // Lowest precedence
    }
    return -1; // Not an operator
}

// Converts an infix expression to a postfix expression
// Returns the number of characters written to the output_stack
int infix_to_postfix(string infix, char* output_stack) {
    stack<char> operator_stack;
    int pos = 0; // Current position in the output stack
    for (int i = 0; i < infix.size(); i++) {
        char c = infix[i];
        if (is_operatorA5(c)) {
            // Handle new ABC operator
            if (c == 'A' || c == 'a') {
                operator_stack.push('A');
                continue;
            }
            else if (c == 'B' || c == 'b') {
                operator_stack.push('B');
                continue;
            }
            else if (c == 'C' || c == 'c') {
                operator_stack.push('C');
                continue;
            }
            // Handle other operators
            while (!operator_stack.empty() && operator_stack.top() != '(' && precedenceA5(operator_stack.top()) >= precedenceA5(c)) {
                output_stack[pos++] = operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push(c);
        }
        else if (c == '(') {
            operator_stack.push(c);
        }
        else if (c == ')') {
            while (!operator_stack.empty() && operator_stack.top() != '(') {
                output_stack[pos++] = operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.pop(); // Discard the left parenthesis
        }
        else {
            // Operand, copy to output stack
            output_stack[pos++] = c;
        }
    }
    // Pop remaining operators from the stack
    while (!operator_stack.empty()) {
        output_stack[pos++] = operator_stack.top();
        operator_stack.pop();
    }
    return pos;
}

///
/// Question2, Part_A_6
/// 
// Node class for doubly linked list
class Node {
public:
    string data;
    Node* next;
    Node* prev;
    Node(string d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

// Doubly linked list based stack class
class StackA6 {
private:
    Node* top_node;
public:
    StackA6() {
        top_node = NULL;
    }
    void push(string data) {
        Node* new_node = new Node(data);
        if (top_node == NULL) {
            top_node = new_node;
        }
        else {
            new_node->next = top_node;
            top_node->prev = new_node;
            top_node = new_node;
        }
    }
    string pop() {
        if (top_node == NULL) {
            return "";
        }
        else {
            string data = top_node->data;
            Node* temp = top_node;
            top_node = top_node->next;
            if (top_node != NULL) {
                top_node->prev = NULL;
            }
            delete temp;
            return data;
        }
    }
    string top() {
        if (top_node == NULL) {
            return "";
        }
        else {
            return top_node->data;
        }
    }
    bool is_empty() {
        return top_node == NULL;
    }
};

// Function to convert an infix expression to postfix expression
string infix_to_postfix(string infix, StackA6& operator_stack) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (c == '(') 
            operator_stack.push("(");
        else if (c == ')') {
            while (!operator_stack.is_empty() && operator_stack.top() != "(") 
                postfix += operator_stack.pop();
            if (!operator_stack.is_empty() && operator_stack.top() == "(") 
                operator_stack.pop();
            
        }
        else if (!is_operator(c)) 
            postfix += c;
        
        else {
            while (!operator_stack.is_empty() && operator_stack.top() != "(") 
                postfix += operator_stack.pop();
            
            operator_stack.push(string(1, c));
        }
    }
    while (!operator_stack.is_empty()) 
        postfix += operator_stack.pop();
    return postfix;
}

///
/// Question2, Part_B_1
/// 
class QueueB {
private:
    string elements;
public:
    QueueB() {}
    void enqueue(char ch) {
        elements += ch;
    }
    char dequeue() {
        char ch = elements[0];
        elements.erase(0, 1);
        return ch;
    }
    char peek_front() {
        return elements[0];
    }
    bool is_empty() {
        return elements.empty();
    }
};

class StackB {
private:
    string elements;
public:
    StackB() {}
    void push(char ch) {
        elements += ch;
    }
    char pop() {
        char ch = elements.back();
        elements.pop_back();
        return ch;
    }
    char top() {
        return elements.back();
    }
    bool is_empty() {
        return elements.empty();
    }
};

bool is_operatorB(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%') {
        return true;
    }
    return false;
}

bool is_operandB(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
        return true;
    }
    return false;
}

int precedenceB(char ch) {
    if (ch == '^') {
        return 3;
    }
    else if (ch == '*' || ch == '/' || ch == '%') {
        return 2;
    }
    else if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

void infix_to_postfix_B1(string infix, string& postfix, QueueB& queue_operator_stack, QueueB& second_queue) {
    int len = infix.length();
    for (int i = 0; i < len; i++) {
        char ch = infix[i];
        if (is_operandB(ch)) {
            postfix += ch;
            if (!second_queue.is_empty()) {
                while (!second_queue.is_empty()) 
                    postfix += second_queue.dequeue();
            }
        }
        else if (is_operatorB(ch)) {
            if (queue_operator_stack.is_empty() || precedenceB(ch) > precedenceB(queue_operator_stack.peek_front())) 
                queue_operator_stack.enqueue(ch);
            
            else {
                while (!queue_operator_stack.is_empty() && precedenceB(ch) <= precedenceB(queue_operator_stack.peek_front())) 
                    second_queue.enqueue(queue_operator_stack.dequeue());               
                queue_operator_stack.enqueue(ch);
            }
        }
        else if (ch == '(') 
            queue_operator_stack.enqueue(ch);
        else if (ch == ')') {
            while (queue_operator_stack.peek_front() != '(') 
                second_queue.enqueue(queue_operator_stack.dequeue());
            queue_operator_stack.dequeue();
        }
    }
    while (!queue_operator_stack.is_empty()) 
        second_queue.enqueue(queue_operator_stack.dequeue());
    while (!second_queue.is_empty()) 
        postfix += second_queue.dequeue();
}

///
/// Question2, Part_B2
/// 
void infix_to_postfix_B2(string infix, string& postfix, QueueB& queue_operator_stack, QueueB& second_queue) {
    int len = infix.length();
    for (int i = 0; i < len; i++) {
        char ch = infix[i];
        if (is_operandB(ch)) {
            postfix += ch;
            if (!second_queue.is_empty()) {
                while (!second_queue.is_empty()) {
                    postfix += second_queue.dequeue();
                }
            }
        }
        else if (is_operatorB(ch)) {
            if (queue_operator_stack.is_empty() || precedenceB(ch) > precedenceB(queue_operator_stack.peek_front())) {
                queue_operator_stack.enqueue(ch);
            }
            else {
                while (!queue_operator_stack.is_empty() && precedenceB(ch) <= precedenceB(queue_operator_stack.peek_front())) {
                    second_queue.enqueue(queue_operator_stack.dequeue());
                }
                queue_operator_stack.enqueue(ch);
            }
        }
        else if (ch == '(') {
            queue_operator_stack.enqueue(ch);
        }
        else if (ch == ')') {
            while (queue_operator_stack.peek_front() != '(') {
                second_queue.enqueue(queue_operator_stack.dequeue());
            }
            queue_operator_stack.dequeue();
        }
    }
    while (!queue_operator_stack.is_empty()) {
        second_queue.enqueue(queue_operator_stack.dequeue());
    }
    while (!second_queue.is_empty()) {
        postfix += second_queue.dequeue();
    }
}

///
/// Question2,Part_C
/// 
class QueueC {
private:
    string elements;
public:
    QueueC() {}
    void enqueue(char ch) {
        elements += ch;
    }
    char dequeue() {
        char ch = elements[0];
        elements.erase(0, 1);
        return ch;
    }
    char peek_front() {
        return elements[0];
    }
    bool is_empty() {
        return elements.empty();
    }
};

class StackC {
private:
    string elements;
public:
    StackC() {}
    void push(char ch) {
        elements += ch;
    }
    char pop() {
        char ch = elements.back();
        elements.pop_back();
        return ch;
    }
    char top() {
        return elements.back();
    }
    bool is_empty() {
        return elements.empty();
    }
};

bool is_operatorC(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%') {
        return true;
    }
    return false;
}

bool is_operandC(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
        return true;
    }
    return false;
}

int precedenceC(char ch) {
    if (ch == '^') {
        return 3;
    }
    else if (ch == '*' || ch == '/' || ch == '%') {
        return 2;
    }
    else if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

void infix_to_postfix_C(string infix, string& postfix, QueueC& queue_operator_stack, QueueC& second_queue) {
    int len = infix.length();
    for (int i = 0; i < len; i++) {
        char ch = infix[i];
        if (is_operandC(ch)) {
            postfix += ch;
            if (!second_queue.is_empty()) {
                while (!second_queue.is_empty()) {
                    postfix += second_queue.dequeue();
                }
            }
        }
        else if (is_operatorC(ch)) {
            if (queue_operator_stack.is_empty() || precedenceC(ch) > precedenceC(queue_operator_stack.peek_front())) {
                queue_operator_stack.enqueue(ch);
            }
            else {
                while (!queue_operator_stack.is_empty() && precedenceC(ch) <= precedenceC(queue_operator_stack.peek_front())) {
                    second_queue.enqueue(queue_operator_stack.dequeue());
                }
                queue_operator_stack.enqueue(ch);
            }
        }
        else if (ch == '(') {
            queue_operator_stack.enqueue(ch);
        }
        else if (ch == ')') {
            while (queue_operator_stack.peek_front() != '(') {
                second_queue.enqueue(queue_operator_stack.dequeue());
            }
            queue_operator_stack.dequeue();
        }
    }
    while (!queue_operator_stack.is_empty()) {
        second_queue.enqueue(queue_operator_stack.dequeue());
    }
    while (!second_queue.is_empty()) {
        postfix += second_queue.dequeue();
    }
}

string infix_reversal(string infix) {
    int len = infix.length();
    string reversed_infix = "";
    for (int i = len - 1; i >= 0; i--) {
        char ch = infix[i];
        if (ch == '(') {
            ch = ')';
        }
        else if (ch == ')') {
            ch = '(';
        }
        reversed_infix += ch;
    }
    return reversed_infix;
}

///
/// Question2,Part_D
/// 
bool is_operatorD(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
        return true;
    return false;
}

int postfix_evaluation(string postfix, int values[]) {
    stack<int> st;
    for (int i = 0; i < postfix.length(); i++) {
        if (is_operatorD(postfix[i])) {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (postfix[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
                case '%':
                    st.push(op1 % op2);
                    break;
                }
        }
        else if (is_operand(postfix[i])) {
            st.push(values[postfix[i] - 'A']);
        }
    }
    return st.top();
}
