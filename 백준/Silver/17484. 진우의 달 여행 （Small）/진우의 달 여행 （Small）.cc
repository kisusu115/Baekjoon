#include<bits/stdc++.h>

using namespace std;
#define COST_MAX 9999
int COST[6][6];
int DP[6][6][3]; // DP[][][0]은 left에서 왔을 때, [1]은 middle, [2]는 right

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> COST[i][j];
		}
	}

	for (int j = 0; j < M; j++) {
		DP[0][j][0] = COST[0][j];
		DP[0][j][1] = COST[0][j];
		DP[0][j][2] = COST[0][j];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j == 0) DP[i][j][0] = COST_MAX;
			else DP[i][j][0] = COST[i][j] + min(DP[i - 1][j - 1][1], DP[i - 1][j - 1][2]);

			DP[i][j][1] = COST[i][j] + min(DP[i - 1][j][0], DP[i - 1][j][2]);

			if (j == M - 1) DP[i][j][2] = COST_MAX;
			else DP[i][j][2] = COST[i][j] + min(DP[i - 1][j + 1][0], DP[i - 1][j + 1][1]);
		}
	}

	int minCost = COST_MAX;
	for (int j = 0; j < M; j++) {
		for (int k = 0; k < 3; k++) {
			minCost = min(minCost, DP[N - 1][j][k]);
		}
	}
	cout << minCost;
	return 0;
}