#include<bits/stdc++.h>

using namespace std;

int N;
string drawing[101];
string drawingForRG[101];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, string* d, char t) {
	if (d[x][y] == 'X') return;
	d[x][y] = 'X';

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N && d[nx][ny] == t) {
			dfs(nx, ny, d, t);
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> drawing[i];
		drawingForRG[i] = drawing[i];
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (drawingForRG[i][j] == 'G') {
				drawingForRG[i][j] = 'R';
			}
		}
	}

	int cnt1 = 0; int cnt2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (drawing[i][j] != 'X') {
				char terminal = drawing[i][j];
				dfs(i, j, drawing, terminal);
				cnt1++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (drawingForRG[i][j] != 'X') {
				char terminal = drawingForRG[i][j];
				dfs(i, j, drawingForRG, terminal);
				cnt2++;
			}
		}
	}
	
	cout << cnt1 << " " << cnt2;
	return 0;
}