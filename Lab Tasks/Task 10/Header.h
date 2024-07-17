#pragma once
#include <string>
#include <iostream>
#include <stack>
using namespace std;

//bool isBalanced(string ex) {
//	stack <char>temp;
//	for (int i=0; i<ex.length(); i++) {
//		if (temp.empty())
//			temp.push(ex[i]);
//        else if ((temp.top() == '(' && ex[i] == ')')
//            || (temp.top() == '{' && ex[i] == '}')
//            || (temp.top() == '[' && ex[i] == ']')) {
//            temp.pop();
//        }
//        else 
//            temp.push(ex[i]);
//        if (temp.empty())
//            return true;
//        return false;
//	}
//}

bool isBalanced(string expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return s.empty();
}

//checks if character is an operator
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') 
        return true;
    else 
        return false;
}

//checks precedence of string
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

//converts from infix to prefix
string infixToPrefix(string ex)
{
    stack<char> s;
    string prefix;
    reverse(ex.begin(), ex.end());

    for (int i = 0; i < ex.length(); i++) {
        if (ex[i] == '(') 
            ex[i] = ')';
        else if (ex[i] == ')') 
            ex[i] = '(';
    }
    for (int i = 0; i < ex.length(); i++) {
        if ((ex[i] >= 'a' && ex[i] <= 'z') || (ex[i] >= 'A' && ex[i] <= 'Z'))
            prefix += ex[i];
        /*if ((ex[i] <= 32 && ex[i] >= 125))
            return false;*/
        else if (ex[i] == '(')
            s.push(ex[i]);
        else if (ex[i] == ')') {
            while ((s.top() != '(') && (!s.empty())) {
                prefix += s.top();
                s.pop();
            }
            if (s.top() == '(')
                s.pop();
        }
        else if (isOperator(ex[i])) {
            if (s.empty())
                s.push(ex[i]);
            else {
                if (precedence(ex[i]) > precedence(s.top()))
                    s.push(ex[i]);
                else if ((precedence(ex[i]) == precedence(s.top()))
                    && (ex[i] == '^')) {
                    while ((precedence(ex[i]) == precedence(s.top()))
                        && (ex[i] == '^')) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(ex[i]);
                }
                else if (precedence(ex[i]) == precedence(s.top()))
                    s.push(ex[i]);
                else {
                    while ((!s.empty()) && (precedence(ex[i]) < precedence(s.top()))) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(ex[i]);
                }
            }
        }
        else
            return false;
    }

    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}