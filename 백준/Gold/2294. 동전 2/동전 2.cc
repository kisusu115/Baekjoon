#include<iostream>
#include<cmath>

using namespace std;
int coins[101];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> coins[i];
	for (int j = 1; j <= k; j++) dp[j] = 10001;

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}
	if (dp[k] == 10001) cout << -1;
	else cout << dp[k];
	return 0;
}