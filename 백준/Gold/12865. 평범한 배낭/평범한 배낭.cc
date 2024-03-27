#include<iostream>
#include<string.h>

using namespace std;

int w[101];
int v[101];
int dp[101][100001] = {0};
int N, K;


int f(int i, int kg) {
	if (i >= N || kg > K) return 0;
	int& ret = dp[i][kg];
	if (ret != -1) return ret;
	if (K - kg >= w[i]) {
		ret = max(f(i + 1, kg), f(i + 1, kg + w[i]) + v[i]);
	}
	else {
		ret = f(i + 1, kg);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		int iptW, iptV;
		cin >> iptW >> iptV;
		w[i] = iptW;
		v[i] = iptV;
	}
	cout << f(0, 0);

	return 0;
}