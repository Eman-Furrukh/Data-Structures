#pragma once
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/// QUESTION 1
string evaluatePostfixExpression(string expression) {
    stack<int> st;
    int operand1, operand2, result;

    // iterate through each character in the expression
    for (char& c : expression) {
        if (c == ' ')
            continue; // skip whitespace
        else if (isdigit(c)) 
            // convert the character to an integer and push it onto the stack
            st.push(c - '0');
        else {
            // pop the top two operands from the stack
            if (st.size() < 2) 
                return "Error: invalid expression"; // not enough operands
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();

            // perform the operation
            switch (c) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0)
                    return "Error: division by zero";
                result = operand1 / operand2;
                break;
            default:
                return "Error: invalid operator";
            }
            st.push(result);
        }
    }

    if (st.size() == 1)
        return std::to_string(st.top());
    else 
        return "Error: invalid expression";
}

/// QUESTION 2
struct Node {
    int data;
    Node* left;
    Node* right;
};

int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

