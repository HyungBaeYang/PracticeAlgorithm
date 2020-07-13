#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
vector<int> parseInts(string str) {
	// Complete this function
	stringstream ss(str);
	char ch;
	int number;
	vector<int> rtnValue;
	while (ss) {
		ss >> number >> ch;
		rtnValue.push_back(number);
	}

	return rtnValue;

}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}

	return 0;
}

