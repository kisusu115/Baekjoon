#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ipt, T; cin >> T;
	while (T--) {
		cin >> ipt;
		int half = ipt / 2;

		for (int i = 0; i < half; i++) {
			if (isPrime(half - i) && isPrime(half + i)) {
				cout << half - i << " " << half + i << "\n";
				break;
			}
		}
	}

	return 0;
}