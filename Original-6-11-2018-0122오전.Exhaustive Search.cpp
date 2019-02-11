#include <iostream>

//가능한 모든 경우의 수를 만들어 보고 탐색.

//Brute Force => 그냥 다 해보는 것.
//경우의 수가 총 몇가지가 나오는지 알아야 한다.
//
//BFS
//재귀, 비트마스크, 순열, 백트레킹.

using namespace std;

int main() {
	//1. 날짜계산.
	//2. 리모컨.
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