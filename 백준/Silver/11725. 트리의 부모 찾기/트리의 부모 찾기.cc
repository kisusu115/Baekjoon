#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> map[100002];
int visited[100002];
int parent[100002];

void dfs(int n) {
	visited[n] = 1;
	for (int i : map[n]) {
		if (visited[i] != 1) {
			parent[i] = n;
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}