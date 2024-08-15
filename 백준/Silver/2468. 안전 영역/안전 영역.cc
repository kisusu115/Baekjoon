#include<iostream>

using namespace std;

int N;
int map[102][102];
int visited[102][102];
pair<int, int> direct[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) };

void makeBoundary() {
	for (int i = 0; i <= N+1; i++) {
		map[0][i] = 0; map[N + 1][i] = 0;
		map[i][0] = 0; map[i][N + 1] = 0;
	}
}

void initVisited() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = 0;
		}
	}
}

void dfs(int m, int n, int h) {
	visited[m][n] = 1;
	for (int i = 0; i < 4; i++) {
		int newM = m + direct[i].first;
		int newN = n + direct[i].second;
		if (map[newM][newN] - h > 0 && visited[newM][newN] == 0) {
			dfs(newM, newN, h);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int maxH = -1;

	cin >> N;
	makeBoundary();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (maxH < map[i][j]) maxH = map[i][j];
		}
	}

	int maxLands = 0;
	for (int h = 0; h <= maxH; h++) {
		int lands = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] - h > 0 && visited[i][j] == 0) {
					lands++;
					dfs(i, j, h);
				}
			}
		}
		if (maxLands < lands) maxLands = lands;
		initVisited();
	}
	cout << maxLands;
	return 0;
}