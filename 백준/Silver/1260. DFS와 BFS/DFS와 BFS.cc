#include<iostream>
#include<queue>
#include<string.h>

using namespace std;
int N, M, V;

int G[1002][1002] = { 0, };
int visited[1002] = { 0, };
queue<int> q;

void dfs(int v) {
	visited[v] = 1;
	cout << v << " ";
	for (int i = 1; i <= N; i++) {
		if (G[v][i] != 0 && visited[i] == 0) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	for (int i = 1; i <= N; i++) {
		if (G[v][i] != 0 && visited[i] == 0) {
			q.push(i);
			visited[i] = 1;
			cout << i << " ";
		}
	}
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		bfs(f);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		G[a][b]++;
		G[b][a]++;
	}
	dfs(V);
	cout << "\n";
	memset(visited, 0, sizeof(int) * 1002);
	visited[V] = 1;
	cout << V << " ";
	bfs(V);
}