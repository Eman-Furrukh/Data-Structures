#include <iostream>
using namespace std;

template <typename T>
T largest(T a, T b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	cout << "int = " << largest(5, 6) << endl;
	cout << "double = " << largest(2.56, 2.36) << endl;
	cout << "string = " << largest("hi", "hey") << endl;
	cout << "character = " << largest('a', 'b') << endl;
	return 0;
}