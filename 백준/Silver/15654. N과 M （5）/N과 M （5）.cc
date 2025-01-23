#include<bits/stdc++.h>

using namespace std;

int N, M;
int num[8];
int ret[8];
bool visited[8];

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << ret[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ret[depth] = num[i];
			dfs(depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> num[i];

	sort(num, num + N);
	dfs(0);

	return 0;
}