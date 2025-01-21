#include<bits/stdc++.h>

using namespace std;

int N, M;
int ret[9];

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) cout << ret[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (depth == 0 || ret[depth - 1] <= i) {
			ret[depth] = i;
			dfs(depth + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	dfs(0);

	return 0;
}