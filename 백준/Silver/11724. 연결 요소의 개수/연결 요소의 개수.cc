#include<iostream>

using namespace std;
int N, M;
int map[1001][1001];
int visited[1001];

void dfs(int n) {
	visited[n] = 1;
	for (int i = 1; i <= N; i++) {
		if (map[n][i] == 1 && visited[i] != 1) {
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		map[u][v] = 1; map[v][u] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
	return 0;
}