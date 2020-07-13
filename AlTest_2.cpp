#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
class Solution {
public:
	vector<string> solution(vector<string> names) {
		map<char, int> spellCalcMap;
		int rtnTotalPoint = 0;
		vector<string> rtnResultVector;
		multimap<int, string, greater<int>> calcedWordMap;	//����Ʈ���� ����ä�� ������ ��� ����
		string tempAlphabet = "ABCDEFGHIJKMNLOPQRSTUVWXYZ";	//������


		//�� ���ĺ��� ����ġ
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