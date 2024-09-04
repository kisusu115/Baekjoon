#include<iostream>

using namespace std;
int DP[31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	DP[0] = 1;
	for (int i = 2; i <= N; i+=2) {
		DP[i] += DP[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			DP[i] += DP[i - j] * 2;
		}
	}
	cout << DP[N];
	return 0;
}