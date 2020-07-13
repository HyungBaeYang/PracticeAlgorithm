#include <iostream>
#include <algorithm>
using namespace std;
string inputString[200000];

//int getSum(string a) {
//	int length = a.length(), sum = 0;
//	for (int i = 0; i < length; i++) {
//		if (a[i] - '0' <= 9 && a[i] = '0' >= 0) {
//			sum += a[i] - '0';
//		}
//	}
//	return sum;
//}
bool stringCompare(string a, string b) {
	if (a.length() < b.length()) {
		return true;
	}
	else if (a.length() > b.length()) {
		return false;
	}

	else {
		/*int aSum = getSum(a);
		int bSum = getSum(b);

		if (aSum != bSum) {
			return aSum < bSum;
		}
		else {
			return a < b;
		}*/
		return a < b;	//사전 순으로 정렬.
	}
}
int main() {
	int len = 0;
	cin >> len;
	for (size_t i = 0; i < len; i++) {
		cin >> inputString[i];
	}
	sort(inputString, inputString + len, stringCompare);

	for (size_t i = 0; i < len; i++) {
		if (i > 0 && inputString[i] == inputString[i - 1])
			continue;
		else {
			cout << inputString[i] << '\n';
		}
	}
	return 0;
}