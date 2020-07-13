#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Seq[i] < Seq[i + 1] 증가
//Seq[i] > Seq[i+1] 감소.

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution {
public:
	int solution(vector<int> seq) {

		vector<int> tempSeq;
		int increaseLenth = 1;
		bool isDecrease = false;
		int rtnResult = 0;
	
		
		for (size_t i = 0; i < seq.size()-1; i++)
		{
			//증가 
			if (seq[i] < seq[i + 1])
			{

				if (isDecrease == true)
				{
					isDecrease = false;
					tempSeq.push_back(increaseLenth);
					increaseLenth = 1;

				}

				increaseLenth++;
			}

			//감소
			else if (seq[i] > seq[i + 1])
			{
				if (isDecrease == false)
				{
					isDecrease = true;
					tempSeq.push_back(increaseLenth);
					increaseLenth = 1;

				}
				increaseLenth++;
			}
			
		}

		if (tempSeq.size() != 0)
		{
			sort(tempSeq.begin(), tempSeq.end());
			rtnResult = tempSeq.back();
		}
		else
			rtnResult = 1;


		return rtnResult;
	}
};


int main() {

	Solution retSolution;
	vector<int> inputVector{ 1,1,1,1,1 };
	int result = retSolution.solution(inputVector);

	cout << "정답 : " << result << endl;

	return 0;
}