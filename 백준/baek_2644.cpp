#include <iostream>
#include <queue>

using namespace std;

int visit[101];
vector<int> graph[101];
int n; // ��ü ����� ��
int person1, person2; // �̼� ���1, ���2
int m; // �� �ڽİ��� ���� ����

int bfs(int person1) {
	queue<int> q;
	q.push(person1);

	while (!q.empty()) {
		int tempQue = q.front();
		q.pop();

		if (tempQue == person2) {
			return visit[person2];
		}
		for (int i = 0; i < graph[tempQue].size(); ++i) {
			int next_Node = graph[tempQue][i];

			if (visit[next_Node] == 0) {
				q.push(next_Node);
				visit[next_Node] = visit[tempQue] + 1;
			}
		}
	}
	return -1;
}

int main() {
	cin >> n;
	cin >> person1 >> person2;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	cout << bfs(person1) << endl;

	return 0;
}