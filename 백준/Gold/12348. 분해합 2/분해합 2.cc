#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	long long n, s = 0; // s는 n의 자릿 수
	long long alwaysN = 0;
	long long answer = 0;
	cin >> n;
	alwaysN = n;

	while (1) {
		n = n / 10;
		s++;
		if (n == 0) break;
	}
	n = alwaysN;

	for (long long i = max(static_cast<long long>(1), n - s * 9); i <= n; i++) {
		long long isN = i;
		long long tmp = i;
		for (long long j = s - 1; j >= 0; j--) {
			long long p = pow(10, j);
			isN += tmp / p;
			tmp = tmp % p;
		}
		if (isN == alwaysN) {
			answer = i;
			break;
		}
	}
	cout << answer;
}
