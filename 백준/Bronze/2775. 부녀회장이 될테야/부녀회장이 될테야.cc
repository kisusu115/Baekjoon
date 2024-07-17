#include<iostream>
#include<vector>

using namespace std;

int apt[2][15] = {0, };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	int k, n;
	int f;
	while (T--) {
		cin >> k >> n;
		for (int i = 0; i <= n; i++) {
			apt[0][i] = i;
		}
		apt[1][0] = 0;
		for (f = 1; f <= k; f++) {
			for (int ho = 1; ho <= n; ho++) {
				if (f % 2 == 1) apt[1][ho] = apt[0][ho] + apt[1][ho - 1];
				else apt[0][ho] = apt[1][ho] + apt[0][ho - 1];
			}
		}
		if (f % 2 == 1) {
			cout << apt[0][n] << "\n";
		}
		else {
			cout << apt[1][n] << "\n";
		}
	}
}