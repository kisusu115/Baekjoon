#include<iostream>

using namespace std;

long long dp[91];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	switch (n) {
	case 0:
		cout << 0;
		return 0;
	case 1:
		cout << 1;
		return 0;
	}
	dp[0] = 0; dp[1] = 1;
	long long ret = 0;
	for (int i = 2; i <= n; i++) {
		ret = dp[i - 1] + dp[i - 2];
		dp[i] = ret;
	}
	cout << ret;
	return 0;
}