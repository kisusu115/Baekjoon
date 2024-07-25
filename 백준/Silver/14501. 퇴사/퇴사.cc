#include<iostream>
#include<string.h>

using namespace std;

int ipt[16][2];	//소요시간, 이익
int dp[16];	//N번째 날에 상담한 경우, 안한 경우 최대값
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(int) * 16 * 2);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ipt[i][0];
		cin >> ipt[i][1];
	}

	int max_pay = 0;
	for (int i = 0; i <= N; i++) {
		dp[i] = max(max_pay, dp[i]);
		if (ipt[i][0] + i <= N) {
			dp[ipt[i][0] + i] = max(dp[ipt[i][0] + i], ipt[i][1] + dp[i]);
		}
		max_pay = max(max_pay, dp[i]);
	}
	cout << max_pay;

	return 0;
}