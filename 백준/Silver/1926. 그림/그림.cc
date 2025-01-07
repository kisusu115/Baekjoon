#include<bits/stdc++.h>

using namespace std;
int pal[501][501];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	if (pal[x][y] != 1) return 0;
	int ret = 1;
	pal[x][y] = -1;
	int nextX, nextY;

	for (int i = 0; i < 4; i++) {
		nextX = x + dx[i];
		nextY = y + dy[i];

		if (nextX >= 0 && nextY >= 0 && pal[nextX][nextY] == 1) {
			ret += dfs(nextX, nextY);
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> pal[i][j];
		}
	}

	int drawCnt = 0;
	int maxV = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pal[i][j] == 1) {
				drawCnt++;
				int checked = dfs(i, j);
				maxV = max(maxV, checked);
			}
		}
	}

	cout << drawCnt << "\n" << maxV;
	return 0;
}