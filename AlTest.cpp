#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Seq[i] < Seq[i + 1] ����
//Seq[i] > Seq[i+1] ����.

//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
class Solution {
public:
	int solution(vector<int> seq) {

		vector<int> tempSeq;
		int increaseLenth = 1;
		bool isDecrease = false;
		int rtnResult = 0;
	
		
		for (size_t i = 0; i < seq.size()-1; i++)
		{
			//���� 
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

			//����
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

	cout << "���� : " << result << endl;

	return 0;
}