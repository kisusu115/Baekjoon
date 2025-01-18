#include<bits/stdc++.h>

using namespace std;
int ipt[1000];
int dp[1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> ipt[i];

	int ret = 0;
	for (int i = 0; i < N; i++) {
		int maxN = 1;
		for (int j = 0; j < i; j++) {
			if (ipt[j] < ipt[i]) {
				maxN = max(maxN, dp[j] + 1);
			}
		}
		dp[i] = maxN;
		ret = max(ret, maxN);
	}

	cout << ret;
	return 0;
}