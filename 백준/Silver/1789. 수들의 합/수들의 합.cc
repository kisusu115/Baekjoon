#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long h = 0;
	long long s;
	cin >> s;

	int i = 1;
	while (1) {
		h += 2 * i;
		if (h >= s) {
			cout << i;
			break;
		}
		h -= i; i++;
	}

	return 0;
}