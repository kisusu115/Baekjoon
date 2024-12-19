#include<bits/stdc++.h>

using namespace std;
int DP[1000001] = {0, };

int minC(int n) {
	if (DP[n] != -1) return DP[n];

	int minCount = minC(n - 1) + 1;
	if (n % 2 == 0) minCount = min(minCount, minC(n / 2) + 1);
	if (n % 3 == 0) minCount = min(minCount, minC(n / 3) + 1);
	DP[n] = minCount;
	return DP[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(DP, -1, sizeof(DP));
	DP[1] = 0;

	int ipt;
	cin >> ipt;
	cout << minC(ipt) << "\n";

	int n = ipt;
	while (n != 0) {
		cout << n << " ";
		if		(n % 3 == 0 && DP[n] == DP[n / 3] + 1) {
			n = n / 3;
		}
		else if (n % 2 == 0 && DP[n] == DP[n / 2] + 1) {
			n = n / 2;
		}
		else if (DP[n] == DP[n - 1] + 1) {
			n = n - 1;
		}
	}
}