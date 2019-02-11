#include <iostream>

using namespace std;
//1, 10, 5, 8, 7, 6, 4, 3, 2, 9

int main() {


	int i, j, temp;

	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (i = 0; i < 9; ++i) {
		j = i;
		while (array[j] > array[j + 1]) {
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
		
	}

	for (int i = 0; i < 10; ++i) {
		cout << array[i] << " ";
	}

	cout << endl;

	return 0;
}