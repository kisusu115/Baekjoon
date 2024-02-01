#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0 };
int num_save[100001] = { 0 };

int number = 1;

void dfs(int V) {
	if (visited[V])return;
	visited[V] = 1;
	num_save[V] = number++;

	for (int i = 0; i < graph[V].size(); i++) {
		dfs(graph[V][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	int f_val, s_val;

	for (int i = 0; i < m; i++) {
		cin >> f_val >> s_val;
		graph[f_val].push_back(s_val);
		graph[s_val].push_back(f_val);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(r);

	for (int i = 1; i <= n; i++) {
		cout << num_save[i] << "\n";
	}
}