#include<iostream>

using namespace std;

bool check(int n) {
	for (int i = 1; i < n; i++) {
		int idx = i;
		int sum = 0;
		sum += idx;
		while (idx != 0) {
			sum += idx % 10;
			idx /= 10;
		}
		if (sum == n) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 10000; i++) {
		if (check(i) == false) cout << i << "\n";
	}
}