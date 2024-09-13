#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;
queue<pair<int, int>> Q;
int dx[] = { -1, 1, 0 ,0 };
int dy[] = { 0, 0, -1 ,1 };

int visited[8][8];
int lab[8][8];
int cpy[8][8];

int N, M, wallCnt = 3;
int ret = 0;

void init() {
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cpy[i][j] = lab[i][j];
		}
	}
}

void bfs() {
	init();
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (lab[x][y] == 2) {
				Q.push({ x, y });
				while (!Q.empty()) {
					pair<int, int> top = Q.front();
					int fx = top.first;
					int fy = top.second;
					Q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = fx + dx[i];
						int ny = fy + dy[i];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (visited[nx][ny] == 0 && lab[nx][ny] != 1) {
							visited[nx][ny] = 1;
							cpy[nx][ny] = 2;
							Q.push({ nx, ny });
						}
					}
				}
			}
		}
	}
	
	int safeCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cpy[i][j] == 0) safeCnt++;
		}
	}
	ret = max(ret, safeCnt);
	return;
}

void wallAndBfs() {
	if (wallCnt == 0) {
		return bfs();
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab[i][j] == 0) {
				wallCnt--;
				lab[i][j] = 1;
				wallAndBfs();
				lab[i][j] = 0;
				wallCnt++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
		}
	}
	wallAndBfs();
	cout << ret;
	return 0;
}