#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B;
	cin >> A >> B;
	int cnt = 0;
	while (B!= 0) {
		if (B == A) {
			cnt++;
			cout << cnt;
			return 0;
		}
		if (B % 2 == 0) {
			B /= 2;
			cnt++;
			continue;
		}
		else if (B % 10 == 1) {
			B = (B - 1) / 10;
			cnt++;
			continue;
		}
		else {
			break;
		}
	}
	cout << -1;
	return 0;
}