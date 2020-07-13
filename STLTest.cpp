#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	vec.push_back(60);
	vec.push_back(70);


	for (vector<int>::size_type i = 0; i < vec.size(); i++) {
		cout << "vec의 " << i + 1 << "번째 원소 :: " << vec[i] << endl;
	}
	

	return 0;
}