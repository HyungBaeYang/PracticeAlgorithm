#include <iostream>

using namespace std;

int number = 10;
int data1[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quickSort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}
	int key = start;	//키는 첫번째 원소.
	int i = start + 1;
	int j = end;

	while (i <= j) {	//엇갈릴 때까지 반복해준다.
		while (data[i] <= data[key]) { //키 값보다 큰 값을 만날 때 까지
			i++;
		}
		while (data[j] >= data[key] && j > start) { //키 값보다 작은 값을 만날 때 까지
			j--;
		}

		if (i > j) { //현재 엇갈린 상태면 키 값과 교체
			swap(data[j], data[key]);
		}
		else {
			swap(data[j], data[i]);
		}
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);

}
int main(void) {

	quickSort(data1, 0, number - 1);
	for (size_t i = 0; i < number; i++) {
		cout << data1[i] << endl;
	}

	return 0;
}