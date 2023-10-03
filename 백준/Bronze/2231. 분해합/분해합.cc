#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int tmp = i;
		int sum = 0;
		while (tmp != 0) {
			sum += tmp % 10;
			tmp = tmp / 10;
		}
		if (sum+i == n) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
	return 0;
}