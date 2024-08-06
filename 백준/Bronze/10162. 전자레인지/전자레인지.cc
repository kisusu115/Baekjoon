#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	if (T % 10 != 0) { cout << -1; return 0; }
	cout << T / 300 << " "; T = T % 300;
	cout << T / 60 << " "; T = T % 60;
	cout << T / 10;
	return 0;
}