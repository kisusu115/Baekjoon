#include<iostream>

using namespace std;

int main() {
	int mush[11] = { 0 };
	int sum = 0;
	int count = 0;

	for (int i = 0; i < 10; i++) {
		cin >> mush[i];
		sum += mush[i];
		if (sum >= 100) {
			if (100 - sum + mush[i] >= sum - 100) {
				cout << sum;
				break;
			}
			else {
				cout << sum - mush[i];
				break;
			}
		}
		count++;
	}
	if (count == 10) {
		cout << sum;
	}
}