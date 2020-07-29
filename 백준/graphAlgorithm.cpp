// graphAlgorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
void bfs(int start, vector<int> graph[], bool check[]) {
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {

		int tempQue = q.front();
		q.pop();
		cout  << tempQue << " ";
		for (size_t i = 0; i < graph[tempQue].size(); ++i) {
			if (check[graph[tempQue][i]] == false) {
				q.push(graph[tempQue][i]);
				check[graph[tempQue][i]] = true;
			}
		}
	}
}
void dfs(int start, vector<int> graph[], bool check[]) {
	stack<int> tempStack; 
	tempStack.push(start);
	check[start] = true;
	cout << start;

	while (!tempStack.empty()) {
		int curr_node = tempStack.top();
		tempStack.pop();
		for (size_t i = 0; i < graph[curr_node].size(); ++i) {
			int next_node = graph[curr_node][i];

			if (check[next_node] == false ) {
				cout << " " << next_node;
				check[next_node] = true;

				tempStack.push(curr_node);
				tempStack.push(next_node);
				break;
			}
		}
	}

	//for (size_t i = 0; i < graph[start].size(); ++i) {
	//	int next = graph[start][i];

	//	// 방문 안했으면 재귀 호출.
	//	if (check[next] == false) {
	//		dfs(next, graph, check);
	//	}
	//}
}

int main()
{
	int n, m, start;

	cin >> n >> m >> start;

	vector<int>* graph = new vector<int>[n + 1];

	bool check[10001];
	fill(check, check + n + 1, false);

	for (size_t i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (size_t i = 1; i <= n; ++i) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(start, graph, check);
	cout << endl;
	memset(check, false, sizeof(check));
	bfs(start, graph, check);
	cout << endl;
}