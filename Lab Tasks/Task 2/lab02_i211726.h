#pragma once
///TASK 1
//adding two numbers
template <typename T>
T add(T a, T b) {
	T temp = 0;
	temp = a + b;
	return temp;
}

/*
template <typename S>
S add(S a[], S b[]) {
	S temp[5];
	for (int i = 0; i < s; i++) {
		temp[i] = a[i] + b[i];
	}
	return temp;
}*/

//subtracting two numbers
template <typename F>
F sub(F a, F b) {
	F temp = 0;
	temp = a - b;
	return temp;
}

//div two numbers
template <typename A>
A Div(A a, A b) {
	A temp = 0;
	temp = a / b;
	return temp;
}

//check prime number
template <typename B>
bool prime(B a) {
	if (a <= 1)
		return false;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}

//check factorial using recursion
template <typename C>
C Fact(C a) {
	if (a == 0)
		return 1;
	return a * Fact(a - 1);
}

//output square root
template <typename D>
D SQRT(D a) {
	return sqrt(a);
}

								///TASK 2
int SplitToSets(int arr[], int s) {
	int s1, s2, temp;
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < s; i++) {
		for (int j = i + 1; j < s; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	if (s % 2 == 0) {
		s1 = s / 2;
		s2 = s - s1;

	}
	else {
		s1 = (s / 2) + 1;
		s2 = s - s1;
	}

	int* arr1 = new int[s1];
	int* arr2 = new int[s2];

	for (int i = 0; i < s1; i++) {
		arr1[i] = arr[i];
	}
	int temp_i = 0;
	for (int i = s1; i < s; i++) {
		arr2[temp_i] = arr[i];
		temp_i += 1;
	}
	for (int i = 0; i < s1; i++) {
		sum1 += arr1[i];
	}
	int temp_j = 0;
	for (int i = s1; i < s; i++) {
		sum2 += arr2[temp_j];
		temp_j += 1;
	}

	return sum1 - sum2;
}


