#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int small[9]{0};
	int sum = 0;
	int m1, m2;

	for (int i = 0; i < 9; i++) {
		cin >> small[i];
		sum += small[i];
	}
	int minus = sum - 100;
	sort(small, small + 9);

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (small[i] + small[j] == minus) {
				m1 = i; 
				m2 = j;
			}
		}
	}
	cout << endl;

	for (int i = 0; i < 9; i++) {
		if (i != m1 && i != m2) {
			cout << small[i] << endl;
		}
	}
}