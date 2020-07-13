#include <iostream>

using namespace std;

int number = 10;
int data1[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quickSort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}
	int key = start;	//Ű�� ù��° ����.
	int i = start + 1;
	int j = end;

	while (i <= j) {	//������ ������ �ݺ����ش�.
		while (data[i] <= data[key]) { //Ű ������ ū ���� ���� �� ����
			i++;
		}
		while (data[j] >= data[key] && j > start) { //Ű ������ ���� ���� ���� �� ����
			j--;
		}

		if (i > j) { //���� ������ ���¸� Ű ���� ��ü
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