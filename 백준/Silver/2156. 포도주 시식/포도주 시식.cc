#include<iostream>
#include<string.h>

using namespace std;

int ipt[10001] = { 0, };
int dp[10001][3] = {0,};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ipt[i];
	}
	dp[0][0] = 0; dp[0][1] = ipt[0]; dp[0][2] = ipt[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + ipt[i];
		dp[i][2] = dp[i - 1][1] + ipt[i];
	}
	int high = 0;
	high = max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
	cout << high;

	return 0;
}