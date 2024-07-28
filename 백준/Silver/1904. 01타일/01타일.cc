#include<iostream>

using namespace std;

int dp[1000003];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[1] = 1; dp[2] = 1;

	cin >> N;
	for (int i = 1; i < N; i++) {
		dp[i] %= 15746;
		dp[i + 1] += dp[i];
		dp[i + 2] += dp[i];
	}
	cout << dp[N] % 15746;
}