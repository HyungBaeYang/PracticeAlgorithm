#include <iostream>

//������ ��� ����� ���� ����� ���� Ž��.

//Brute Force => �׳� �� �غ��� ��.
//����� ���� �� ����� �������� �˾ƾ� �Ѵ�.
//
//BFS
//���, ��Ʈ����ũ, ����, ��Ʈ��ŷ.

using namespace std;

int main() {
	//1. ��¥���.
	//2. ������.
	int E, S, M;
	cin >> E >> S >> M;

	int e = 1, s = 1, m = 1;


	for (int i = 1; ; ++i) {
		if (e == E && s == S && m == M) {
			cout << i << endl;
			break;
		}
		e += 1;
		s += 1;
		m += 1;

		if (e == 16) {
			e = 1;
		}
		if (s == 29) {
			s = 1;
		}
		if (m == 20) {
			m = 1;
		}
	}

	return 0;
}