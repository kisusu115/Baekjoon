#include<iostream>

using namespace std;

bool check(int n) {
	if (n >= 100) {
		int h, t, o;
		h = n / 100;
		t = (n % 100) / 10;
		o = n % 10;
		if (h - t == t - o) return true;
		else return false;
	}
	else {
		return true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (check(i)) cnt++;
	}
	cout << cnt;
	return 0;
}