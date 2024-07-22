#include<iostream>
#include<cmath>

using namespace std;

int dp[1000] = { 0, };

int getnum(int n) {
	if (dp[n] != 0)return dp[n];
	int ret = getnum(n - 1) + getnum(n - 2) * 2;
	ret %= 10007;
	dp[n] = ret;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[0] = 1; dp[1] = 3;

	int n;
	cin >> n;
	cout << getnum(n-1);
}