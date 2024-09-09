#include<iostream>
#include<string.h>

using namespace std;
unsigned long long DP[31][31];

unsigned long long NS(int w, int h) {
	if (DP[w][h] != -1) return DP[w][h];
	unsigned long long ret = 0;
	if (w == 0) ret = NS(w, h - 1);
	else {
		if (h == 0) ret = NS(w - 1, h + 1);
		else ret = NS(w - 1, h + 1) + NS(w, h - 1);
	}
	return DP[w][h] = ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 0;
	while (cnt < 1000) {
		cnt++;
		int N; cin >> N;
		if (N == 0) break;

		memset(DP, -1, sizeof(DP));
		DP[1][0] = 1; DP[0][1] = 1;
		cout << NS(N, 0) << "\n";
	}
	return 0;
}