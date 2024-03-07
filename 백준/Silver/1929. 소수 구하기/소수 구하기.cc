#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {
	if (n == 1)return false;
	int prime = true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int num = N; num <= M; num++) {
		if (isPrime(num)) cout << num << "\n";
	}

	return 0;
}