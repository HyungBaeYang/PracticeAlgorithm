#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {
	cin >> s;
	int resultCount = 1;
	for (size_t i = 0; i < s.size(); i++) {
		if (isupper(s[i])) {
			resultCount++;
		}

	}
	return resultCount;
}

int main()
{
	string inputStr = "";
	
	int resultCount = camelcase(inputStr);
	
	cout << resultCount << endl;
	

	return 0;
}
