#include <iostream>
#include <string>
#include <cctype>


using namespace std;
// 적어도 6자리 숫자를 입력해야하고 3자리수가 안되면 적어도 6으로 사이즈 맞춰야함.
// 인풋스트링값을 가지고 size만큼 for 문 돌면서 각 문자에 숫자는 있는지, 소문자, 대문자, 특수문자는 있는지 확인.
// 있다면 그냥 내비둬.
// 없다면 뭐가 없는지 확인 후 리턴.


// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
	// Return the minimum number of characters to make the password strong
	int strCount = 0;
	int number = 0;
	int lower_case = 0;
	int upper_case = 0;
	int special_characters = 0;


	for (size_t i = 0; i < n; ++i) {
		if (isupper(password[i])) {
			//입력한 문자 중 대문자가 있는지 확인.
			upper_case++;
		}
		else if (islower(password[i])) {
			// 입력한 문자중 소문자가 있는지 확인.
			lower_case++;
		}
		else if (isdigit(password[i])) {
			// 입력한 문자중 숫자가 있는지 확인.
			number++;
		}
		else {
			// 입력한 문자중 특수기호가 있는지 확인.
			special_characters++;
		}
	}
	
	if (number > 0) {
		strCount += number;
	}
	if (lower_case > 0) {
		strCount += lower_case;
	}
	if (upper_case > 0) {
		strCount += upper_case;
	}
	if (special_characters > 0) {
		strCount += special_characters;
	}


	if (n + strCount >= 6) {
		//이상이면 그냥 카운트 리턴.
		//cout << strCount << endl;
		return strCount;
	}
	else {
		//적어도 최소 길이 6은 되야함.
		//cout << 6 - strCount << endl;
		return 6 - strCount;
	}
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string password;
	getline(cin, password);

	int answer = minimumNumber(n, password);

	cout << answer << "\n";

	//fout.close();

	return 0;
}
