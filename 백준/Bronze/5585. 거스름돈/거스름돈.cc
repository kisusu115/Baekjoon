#include<iostream>

using namespace std;

int getnum(int a) {
	int left = a;
	int ret = 0;
	while (left > 0) {
		if (left >= 500) {
			left -= 500;
			ret++;
		}else if (left >= 100) {
			ret += left / 100;
			left %= 100;
		}else if (left >= 50) {
			left -= 50;
			ret++;
		}
		else if (left >= 10) {
			ret += left / 10;
			left %= 10;
		}
		else if (left >= 5) {
			left -= 5;
			ret++;
		}
		else if (left >= 1) {
			ret += left;
			left = 0;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int pay;
	cin >> pay;
	cout << getnum(1000-pay);

	return 0;
}