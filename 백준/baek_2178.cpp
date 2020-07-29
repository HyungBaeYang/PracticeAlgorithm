#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

string graph[100];
int visit[100][100];

// 시계방향
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs(int x, int y, int row, int col) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	visit[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if ((nextX >= 0 && nextY >= 0) && (nextX < row && nextY < col)) {	//그래프 국룰 조건
				if (visit[nextX][nextY] == 0 && graph[nextX][nextY] == '1') {
					q.push(make_pair(nextX, nextY));
					visit[nextX][nextY] = visit[x][y] + 1;
				}
			}
			
		}
	}
}

int main() {
	int row, col;
	cin >> row >> col;

	for (int i = 0; i < row; ++i) {
			cin >> graph[i];
	}

	bfs(0, 0,row, col);
	cout << visit[row - 1][col - 1];

	return 0;
}