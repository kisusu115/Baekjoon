#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	if (!N) cout << 0;
	long long e0 = 0;
	long long e1 = 1;
	long long paste0;
	for (int i = 1; i < N; i++) {
		paste0 = e0;
		e0 = paste0 + e1;
		e1 = paste0;
	}
	cout << e0 + e1;
}