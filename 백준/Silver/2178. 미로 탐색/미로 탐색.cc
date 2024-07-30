#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
char map[102][102];
int dist[102][102];
vector<pair<int, int>> D = { make_pair(0, -1), make_pair(0, 1), make_pair(-1, 0), make_pair(1, 0) };
queue<pair<int, int>> q;

void bfs(int x, int y) {
	map[x][y] = 'X';
	q.push(make_pair(x, y));
	dist[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = x + D[i].first;
			int nextY = y + D[i].second;

			if (map[nextX][nextY] == '1') {
				map[nextX][nextY] = 'X';
				q.push(make_pair(nextX, nextY));
				dist[nextX][nextY] = dist[x][y] + 1;
			}
		}
	}
}

void makeBoundary() {
	for (int i = 0; i <= N+1; i++) {
		map[i][0] = 0;
		map[i][M+1] = 0;
	}
	for (int j = 0; j <= M+1; j++) {
		map[0][j] = 0;
		map[N+1][j] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	makeBoundary();
	string ipt;
	for (int i = 1; i <= N; i++) {
		cin >> ipt;
		int j = 1;
		for (char c : ipt) {
			map[i][j] = c;
			j++;
		}
	}

	bfs(1, 1);
	cout << dist[N][M];
}