#include<iostream>

using namespace std;

int main() {
	int n, result = 0;
	int x, cnt;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt = 0;
		for (int j = 1; j <= x; j++) {
			if (x % j == 0) {
				cnt++;
			}
		}
		if (cnt == 2) {
			result++;
		}
	}

	cout << result;
    return 0;
}