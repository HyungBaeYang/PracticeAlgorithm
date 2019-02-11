#include <iostream>

using namespace std;
//1, 10, 5, 8, 7, 6, 4, 3, 2, 9
//3, 7, 8, 1, 5, 9, 6, 10, 2, 4

//�� ������ �Ǻ��� �������� ������ ������ ���� �˰���.

int number = 10;
int data_s[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
void Draw() {
	int i = 0;
	for (i = 0; i < number; ++i) {
		cout << data_s[i] << " ";
	}
}
void QuickSort(int* data, int start, int end) {
	//���Ұ� 1���� ��쿡 �״�� ���д�.
	if (start >= end) {
		return;
	}

	int key = start;	// Ű�� ù ��° ���Ҹ� ���Ѵ�.
	int i = start + 1;
	int j = end;
	int temp;

	//���۰� ���� ������ �� ���� �ݺ�.
	while (i <= j) {
		//Ű ������ ū ���� ������ ����
		while (i <= end && data[i] <= data[key]) { i++; }
		//Ű ������ ���� ���� ������ ����
		while (j > start && data[j] >= data[key]) { j--; }


		// ���� ������ ���¸� Ű ���� ��ü
		if (i > j) { 
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		// �������� �ʾҴٸ� i�� j�� ��ü
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}


	}

	QuickSort(data, start, j - 1);
	QuickSort(data, j + 1, end);
}
int main() {
	QuickSort(data_s, 0, number - 1);
	Draw();

	return 0;
}