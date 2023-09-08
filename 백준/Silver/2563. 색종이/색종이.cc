#include<iostream>

using namespace std;

int main() {
	bool white[100][100] = {false};
	int count = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int left, bottom;
		cin >> left >> bottom;

		for (int j = left; j < left+10; j++) {
			for (int k = 90-bottom; k < 100-bottom; k++) {
				white[j][k] = true;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (white[i][j]) count++;
		}
	}

	cout << count;

	return 0;
}