#include <iostream>

using namespace std;
//1, 10, 5, 8, 7, 6, 4, 3, 2, 9
//3, 7, 8, 1, 5, 9, 6, 10, 2, 4

//퀵 정렬은 피봇을 기준으로 반으로 나누는 정렬 알고리즘.

int number = 10;
int data_s[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
void Draw() {
	int i = 0;
	for (i = 0; i < number; ++i) {
		cout << data_s[i] << " ";
	}
}
void QuickSort(int* data, int start, int end) {
	//원소가 1개인 경우에 그대로 냅둔다.
	if (start >= end) {
		return;
	}

	int key = start;	// 키는 첫 번째 원소를 뜻한다.
	int i = start + 1;
	int j = end;
	int temp;

	//시작과 끝이 엇갈릴 때 까지 반복.
	while (i <= j) {
		//키 값보다 큰 값을 만날때 까지
		while (i <= end && data[i] <= data[key]) { i++; }
		//키 값보다 작은 값을 만날때 까지
		while (j > start && data[j] >= data[key]) { j--; }


		// 현재 엇갈린 상태면 키 값과 교체
		if (i > j) { 
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		// 엇갈리지 않았다면 i와 j를 교체
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