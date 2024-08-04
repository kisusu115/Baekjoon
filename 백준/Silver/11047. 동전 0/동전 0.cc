#include<iostream>
#include<cmath>

using namespace std;
int N, K;
int coins[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}

	for (int i = N - 1; i >=0; i--) {
		num += K / coins[i];
		K %= coins[i];
	}

	cout << num;
	return 0;
}