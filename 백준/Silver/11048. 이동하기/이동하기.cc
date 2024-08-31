#include<iostream>

using namespace std;
int arr[1001][1001];
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + arr[i][j];
		}
	}

	cout << dp[N][M];
	return 0;
}