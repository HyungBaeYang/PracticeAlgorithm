#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution {
public:
	vector<string> solution(vector<string> names) {
		map<char, int> spellCalcMap;
		int rtnTotalPoint = 0;
		vector<string> rtnResultVector;
		multimap<int, string, greater<int>> calcedWordMap;	//포인트들을 계산된채로 맵으로 담는 역할
		string tempAlphabet = "ABCDEFGHIJKMNLOPQRSTUVWXYZ";	//데이터


		//각 알파벳당 가중치
		for (size_t i = 0; i < tempAlphabet.size(); i++) {
			spellCalcMap.insert(make_pair(tempAlphabet[i], i+1));
		}

		for (size_t i = 0; i < names.size(); i++) {
			for (size_t j = 0; j < names[i].size(); j++) {
				rtnTotalPoint += spellCalcMap[names[i][j]];
			}
			
			if (names[i] == "JOHN") {
				rtnTotalPoint = 9999;
			}
			
			calcedWordMap.insert(make_pair(rtnTotalPoint, names[i]));
			rtnTotalPoint = 0;
		}

		multimap<int, string, greater<int>>::iterator iter;

		for (iter = calcedWordMap.begin(); iter != calcedWordMap.end(); iter++) {
			rtnResultVector.push_back(iter->second);
			
		}
		return rtnResultVector;
	}
};



int main() {
	Solution solution;
	vector<string> retVector{ "BATMAN","SUPERMAN", "JOHN","SPIDERMAN","TERMINATOR", "JOHN", "IRONMAN","AA","B", "JOHN"};

	vector<string> resultVector = solution.solution(retVector);
	for (size_t i = 0; i < resultVector.size(); i++)
	{
		cout << resultVector[i] << " ";
	}
	return 0;
}