#include <iostream>
#include <string>
#include <cctype>


using namespace std;
// ��� 6�ڸ� ���ڸ� �Է��ؾ��ϰ� 3�ڸ����� �ȵǸ� ��� 6���� ������ �������.
// ��ǲ��Ʈ������ ������ size��ŭ for �� ���鼭 �� ���ڿ� ���ڴ� �ִ���, �ҹ���, �빮��, Ư�����ڴ� �ִ��� Ȯ��.
// �ִٸ� �׳� �����.
// ���ٸ� ���� ������ Ȯ�� �� ����.


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
			//�Է��� ���� �� �빮�ڰ� �ִ��� Ȯ��.
			upper_case++;
		}
		else if (islower(password[i])) {
			// �Է��� ������ �ҹ��ڰ� �ִ��� Ȯ��.
			lower_case++;
		}
		else if (isdigit(password[i])) {
			// �Է��� ������ ���ڰ� �ִ��� Ȯ��.
			number++;
		}
		else {
			// �Է��� ������ Ư����ȣ�� �ִ��� Ȯ��.
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
		//�̻��̸� �׳� ī��Ʈ ����.
		//cout << strCount << endl;
		return strCount;
	}
	else {
		//��� �ּ� ���� 6�� �Ǿ���.
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
