#include <iostream>
#include <string>

using namespace std;

//string SwapTemp()
int main() {

	string inputA = "";
	string inputB = "";
	
	string plusStr = "";
	string resultStr = "";
	cin >> inputA;
	cin >> inputB;
	

	int sizeA = inputA.size();	//문자열의 사이즈는 미리 해둬야함... 이유는 잘 모르곘음..ㅠ
	int sizeB = inputB.size();

	plusStr = inputA + inputB;
	resultStr = plusStr;

	cout << sizeA << " " << sizeB << endl;

	char tempA, tempB;

	tempA = plusStr[0];
	tempB = plusStr[sizeA];

	plusStr[0] = tempB;
	plusStr[sizeA] = tempA;
	cout << inputA + inputB << endl;
	for (int i = 0; i < sizeA; ++i) {
		cout << plusStr[i];
	}
	cout << " ";
	for (size_t i = sizeA; i < plusStr.size(); ++i) {
		cout << plusStr[i];
	}

	return 0;
}