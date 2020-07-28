#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int cnt;
string graph[100];
bool visit[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<int> cnt_vec;
void dfs(int x, int y) {
	visit[x][y] = 1;
	for (size_t i = 0; i < 4; ++i) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (graph[nextX][nextY] == '1' && visit[nextX][nextY] == false) {
			cnt++;
			dfs(nextX, nextY);
		}

	}
}
int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		cin >> graph[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (graph[i][j] == '1' && visit[i][j] == false) {
				dfs(i, j);
				cnt_vec.push_back(cnt);
			}
		}
	}

	for (int i = 0; i < cnt_vec.size(); ++i) {
		cout << cnt_vec[i] << endl;
	}

	return 0;
}