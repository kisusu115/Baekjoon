#include<iostream>

using namespace std;
long long DP[201][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K; cin >> N >> K;
	for (int i = 1; i < 201; i++) DP[i][0] = 0;
	for (int i = 0; i < 201; i++) DP[i][1] = 1;
	for (int i = 2; i <= K;  i++) DP[0][i] = 1;

	for (int j = 1; j <= N; j++) {
		for (int k = 2; k <= K; k++) {
			for (int i = 0; i <= j; i++) {
				DP[j][k] += DP[j - i][k - 1];
				if (DP[j][k] >= 1000000000) DP[j][k] %= 1000000000;
			}
		}
	}

	cout << DP[N][K];
	return 0;
}