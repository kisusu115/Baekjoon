#include<iostream>
#include<tuple>
#include<queue>
#include<vector>

using namespace std;
int M, N, H;
int tom[102][102][102];
queue<tuple<int, int, int>> q;
tuple<int, int, int> direct[6] = { make_tuple(-1, 0, 0), make_tuple(1, 0, 0), make_tuple(0, -1, 0), make_tuple(0, 1, 0), make_tuple(0, 0, -1), make_tuple(0, 0, 1) };


void makeBoundary() {
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			tom[0][i][j] = -1;
			tom[H+1][i][j] = -1;
		}
	}
	for (int j = 0; j <= M + 1; j++) {
		for (int k = 0; k <= H + 1; k++) {
			tom[k][0][j] = -1;
			tom[k][N+1][j] = -1;
		}
	}
	for (int k = 0; k <= H + 1; k++) {
		for (int i = 0; i <= N + 1; i++) {
			tom[k][i][0] = -1;
			tom[k][i][M+1] = -1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;
	makeBoundary();

	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> tom[k][i][j];
				if (tom[k][i][j] == 1) {
					q.push(make_tuple(k, i, j));
				}
			}
		}
	}

	while (!q.empty()) {
		int k = get<0>(q.front());
		int i = get<1>(q.front());
		int j = get<2>(q.front());
		q.pop();

		for (int n = 0; n < 6; n++) {
			int newK = k + get<0>(direct[n]);
			int newI = i + get<1>(direct[n]);
			int newJ = j + get<2>(direct[n]);

			if (tom[newK][newI][newJ] == 0) {
				tom[newK][newI][newJ] = tom[k][i][j] + 1;
				q.push(make_tuple(newK, newI, newJ));
			}
		}
	}
	int max = 0;

	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (tom[k][i][j] == 0) {
					cout << -1;
					return 0;
				}
				if (tom[k][i][j] > max) {
					max = tom[k][i][j];
				}
			}
		}
	}
	cout << max - 1;
	return 0;
}