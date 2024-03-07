#include<iostream>
#include<cmath>
#include<vector>

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

	vector<int> vect;
	for (int i = 1; i <= 123456 * 2; i++) {
		if (isPrime(i)) vect.push_back(i);
	}
	
	while (1) {
		int N;
		cin >> N;
		if (N == 0)break;
		int count = 0;

		for (int index = 0; index < vect.size(); index++) {
			if (N < vect[index] && vect[index] <= 2 * N) count++;
		}
		cout << count << "\n";
	}
	return 0;
}