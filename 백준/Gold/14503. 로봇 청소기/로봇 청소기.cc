#include<bits/stdc++.h>

using namespace std;

int N, M;
int room[50][50];

bool checkBack(int r, int c) {
	if (c - 1 >= 0 && room[r][c - 1] == 0) return false;
	if (r - 1 >= 0 && room[r - 1][c] == 0) return false;
	if (c + 1 < M && room[r][c + 1] == 0) return false;
	if (r + 1 < N && room[r + 1][c] == 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}

	while (1) {
		room[r][c] = -1;
		bool back = checkBack(r, c);

		if (back) {
			if (d == 0) {
				if (r + 1 < N && room[r + 1][c] != 1) r++;
				else break;
			}
			else if (d == 1) {
				if (c - 1 >= 0 && room[r][c - 1] != 1) c--;
				else break;
			}
			else if (d == 2) {
				if (r - 1 >= 0 && room[r - 1][c] != 1) r--;
				else break;
			}
			else if (d == 3) {
				if (c + 1 < M && room[r][c + 1] != 1) c++;
				else break;
			}
			continue;
		}

		if (d == 0) {
			if (c - 1 >= 0 && room[r][c - 1] == 0) {
				c--;
				d = 3;
			}
			else {
				d = 3;
				continue;
			}
		}
		else if (d == 1) {
			if (r - 1 >= 0 && room[r - 1][c] == 0) {
				r--;
				d = 0;
			}
			else {
				d = 0;
				continue;
			}
		}
		else if (d == 2) {
			if (c + 1 < M && room[r][c + 1] == 0) {
				c++;
				d = 1;
			}
			else {
				d = 1;
				continue;
			}
		}
		else if (d == 3) {
			if (r + 1 < N && room[r + 1][c] == 0) {
				r++;
				d = 2;
			}
			else {
				d = 2;
				continue;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (room[i][j] == -1) {
				ret++;
			}
		}
	}

	cout << ret; 
	return 0;
}