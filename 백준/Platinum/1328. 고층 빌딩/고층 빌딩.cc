#include<iostream>
#include<string.h>

#define DIVIDE 1000000007

using namespace std;
unsigned long long DP[101][101][101];
unsigned long long C[101][101];

unsigned long long combination(int a, int b) {
	if (C[a][b] != -1) return C[a][b];
	unsigned long long ret;
	if (a == b || b == 0) ret = 1;
	else ret = combination(a - 1, b - 1) + combination(a - 1, b);
	ret %= DIVIDE;
	C[a][b] = ret;
	return ret;
}

unsigned long long GS(int n, int l, int r) {
	if (DP[n][l][r] != -1) return DP[n][l][r];
	if (l + r > n + 1) return DP[n][l][r] = 0;
	if (l + r == n + 1) return DP[n][l][r] = combination(n-1, l-1);
	
	unsigned long long sum = 0;
	if (l == 1) {
		for (int i = 1; i <= n - r + 1; i++) {
			sum += GS(n - 1, i, r - 1);
		}
	}
	else if (r == 1) {
		for (int i = 1; i <= n - l + 1; i++) {
			sum += GS(n - 1, l - 1, i);
		}
	}
	else {
		for (int i = l - 1; i <= n - r; i++) {
			unsigned long long Lsum = 0; unsigned long long Rsum = 0;
			for (int j = 1; j <= i - l + 2; j++) {
				Lsum += GS(i, l - 1, j);
			}
			for (int j = 1; j <= n - i - r + 1; j++) {
				Rsum += GS(n - 1 - i, j, r - 1);
			}
			sum += (((Lsum % DIVIDE) * (Rsum % DIVIDE)) % DIVIDE) * combination(n - 1, i) % DIVIDE;
			sum %= DIVIDE;
		}
	}
	DP[n][l][r] = sum %= DIVIDE;
	return DP[n][l][r];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, L, R; cin >> N >> L >> R;
	memset(DP, -1, sizeof(DP));
	memset(C, -1, sizeof(C));

	for (int i = 2; i <= 100; i++) DP[i][1][1] = 0;
	cout << GS(N, L, R);
	return 0;
}