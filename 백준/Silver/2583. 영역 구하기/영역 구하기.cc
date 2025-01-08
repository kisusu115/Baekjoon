#include<bits/stdc++.h>

using namespace std;

int M, N, K;
int paper[101][101];

vector<int> extents;
queue<pair<int, int>> q;

int nx[4] = { 0, 0, 1, -1 };
int ny[4] = { 1, -1, 0, 0 };

int bfs(int x, int y) {
	int extent = 0;
	q.push(make_pair(x, y));
	paper[x][y] = -1;

	int nowX, nowY;
	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		extent++;

		for (int i = 0; i < 4; i++) {
			int nextX, nextY;
			nextX = nowX + nx[i];
			nextY = nowY + ny[i];

			if (nextX >= 0 && nextY >= 0 && nextX < N && nextY < M && paper[nextX][nextY] == 0) {
				q.push(make_pair(nextX, nextY));
				paper[nextX][nextY] = -1;
			}
		}
	}

	return extent;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(paper, 0, sizeof(paper));
	cin >> M >> N >> K;

	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				paper[x][y] = 1;
			}
		}
	}
	int cnt = 0;

	for (int x= 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (paper[x][y] == 0) {
				cnt++;
				extents.push_back(bfs(x, y));
			}
		}
	}

	sort(extents.begin(), extents.end());

	cout << cnt << "\n";
	for (int e : extents) cout << e << " ";

	return 0;
}