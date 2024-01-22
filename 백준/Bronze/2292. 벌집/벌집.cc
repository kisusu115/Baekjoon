#include<iostream>

using namespace std;

int main() {
	int count = 1;
	int ipt;
	cin >> ipt;
	if (ipt == 1) {
		cout << 1;
		return 0;
	}

	int floor = (ipt - 2) / 6 ;
	while (floor >= 0) {
		floor -= count;
		count++;
		if (floor < 0) {
			cout << count;
			break;
		}
	}
	return 0;
}