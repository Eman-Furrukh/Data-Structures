#include <iostream>
using namespace std;

template <typename T>
void concatenate(T a[], int s1, T b[], int s2) {
	T temp[6];
	for (int i = 0; i < s1; i++)
	{
		temp[i] = a[i];
	}
	for (int j = 0; j < s2; j++)
	{
		temp[3 + j] = b[j];
	}

	for (int i = 0; i < 6; i++)
		cout << temp[i];

	/*T arr[] = {};
	for (int i = 1; i < 6; i++)
	{
		if (temp[0] == temp[i])
			arr[0];
	}
	cout << arr;*/

}

int main() {
	int arr1[3] = {1,2,3};
	int arr2[3] = {3,5,1};
	concatenate<int>(arr1, 3, arr2, 3);
	cout << endl;
	return 0;
}




