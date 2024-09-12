#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
#define MAX 501

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int map[MAX][MAX];
int DP[MAX][MAX];
int n;

int dfs(int x, int y) {
	if (DP[x][y] != -1) return DP[x][y];
	int maxi = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (map[x][y] < map[nx][ny]) {
			maxi = max(maxi, dfs(nx, ny) + 1);
		}
	}
	return DP[x][y] = maxi;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			DP[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (DP[i][j] == -1) dfs(i, j);
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret = max(ret, DP[i][j]);
		}
	}
	cout << ret;
	return 0;
}