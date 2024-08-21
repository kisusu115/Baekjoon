#include<iostream>

using namespace std;

char map[51][51];

void init(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string low;
		cin >> low;
		for (int j = 0; j < M; j++) {
			map[i][j] = low[j];
		}
	}
	int min_cnt1 = 99999;
	for (int i = 0; i < N-7; i++) {
		for (int j = 0; j < M-7; j++) {
			int cnt = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if ((i + j + k + l) % 2 == 0 && map[i + k][j + l] == 'B') cnt++;
					if ((i + j + k + l) % 2 == 1 && map[i + k][j + l] == 'W') cnt++;
				}
			}
			min_cnt1 = min(min_cnt1, cnt);
		}
	}
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int cnt = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if ((i + j + k + l) % 2 == 0 && map[i + k][j + l] == 'W') cnt++;
					if ((i + j + k + l) % 2 == 1 && map[i + k][j + l] == 'B') cnt++;
				}
			}
			min_cnt1 = min(min_cnt1, cnt);
		}
	}

	cout << min_cnt1;
	return 0;
}