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
	int index = 1;
	while (floor >= 0) {
		floor -= index;
		if (floor < 0) {
			cout << ++count;
			break;
		}
		index++;
		count++;
	}
	return 0;
}