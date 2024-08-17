#include<iostream>
#include<queue>

using namespace std;
pair<int, int> direct[8] = { make_pair(1, 2), make_pair(2, 1), make_pair(-1, -2), make_pair(-2, -1),
						 	 make_pair(-1, 2), make_pair(2, -1), make_pair(1, -2), make_pair(-2, 1) };

int L;
int map[301][301];
int visited[301][301];
int sx, sy, ex, ey;
queue<pair<int, int>> q;

void init(int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			visited[i][j] = 0;
			map[i][j] = 0;
		}
	}
	while (!q.empty()) {
		q.pop();
	}
}

void bfs(int x, int y) {
	q.push(make_pair(x, y));
	visited[y][x] = 1;
	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();
		if (X == ex && Y == ey) {
			cout << map[Y][X] << "\n";
			while (!q.empty()) q.pop();
			break;
		}

		for (int i = 0; i < 8; i++) {
			int newX = X + direct[i].first;
			int newY = Y + direct[i].second;
			if (newX >= 0 && newY >= 0 && newX < L && newY < L && visited[newY][newX] == 0) {
				q.push(make_pair(newX, newY));
				visited[newY][newX] = 1;
				map[newY][newX] = map[Y][X] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> L;
		cin >> sx >> sy >> ex >> ey;
		bfs(sx, sy);
		init(L);
	}
}