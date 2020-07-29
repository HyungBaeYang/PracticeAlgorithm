#include <iostream>

using namespace std;

bool visit[101];
int graph[101][101];
int n, cnt;


void dfs(int start) {

	visit[start] = true;
	for (int i = 1; i <= n; ++i) {
		if (graph[start][i] == 1 && !visit[i]) {
			cnt++;
			dfs(i);
		}
	}
}
int main() {
	int con;
	int u, v;
	cin >> n;
	cin >> con;
	for (int i = 0; i < con; ++i) {
		cin >> u >> v;
		graph[u][v] = graph[v][u] = 1;
	}
	dfs(1);
	cout << cnt << endl;

	return 0;
}