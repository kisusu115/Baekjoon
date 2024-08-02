#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int M, N;
int tom[1002][1002];
queue<pair<int, int>> q;
pair<int, int> direct[4] = { make_pair(-1,0), make_pair(1,0), make_pair(0,-1), make_pair(0,1) };

void makeBoundary() {
	for (int i = 0; i <= N + 1; i++) {
		tom[i][0] = -1;
		tom[i][M+1] = -1;
	}
	for (int j = 0; j <= M + 1; j++) {
		tom[0][j] = -1;
		tom[N+1][j] = -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	makeBoundary();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tom[i][j];
			if (tom[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = x + direct[i].first;
			int newY = y + direct[i].second;
			if (tom[newX][newY] == 0) {
				q.push(make_pair(newX, newY));
				tom[newX][newY] = tom[x][y] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (tom[i][j] == 0) {
				cout << -1; 
				return 0;
			}
			if (tom[i][j] > max) {
				max = tom[i][j];
			}
		}
	}
	cout << max - 1;
	return 0;
}