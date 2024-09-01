#include<iostream>

using namespace std;
int arr[502][502];
int dp[501][501];
int M, N;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void make_boundary() {
	for (int i = 0; i <= M + 1; i++) {
		arr[i][0] = 10001; arr[i][N+1] = 10001;
	}
	for (int j = 0; j <= N + 1; j++) {
		arr[0][j] = 10001; arr[M+1][j] = 10001;
	}
}

int dfs(int x, int y) {
	if (x == M && y == N) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (arr[nx][ny] < arr[x][y]) {
			dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	make_boundary();
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(1, 1);
	return 0;
}