#include <iostream>
using namespace std;

template <typename T>
void swap(T a, T b) {
	cout << "Before swapping :\n";
	cout << a << endl << b << endl;
	T temp;
	temp = a;
	a = b;
	b = temp;
	cout << "After swapping :\n";
	cout << a << endl << b << endl << endl;
}

int main() {
	cout << "int :\n";
	swap(5, 6);
	cout << "double :\n";
	swap(2.56, 2.36);
	cout << "string :\n";
	swap("hi", "hey");
	cout << "char :\n";
	swap('a', 'b');

	return 0;
}