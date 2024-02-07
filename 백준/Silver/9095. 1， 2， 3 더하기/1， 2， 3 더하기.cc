#include <iostream>
using namespace std;

int MemoryArray[11] = {0};
int IsUsed[11] = { 0 };

int countNum(int index) {
	if (IsUsed[index-1])return MemoryArray[index-1];
	IsUsed[index-1] = 1;
	int thisVal = countNum(index - 1) + countNum(index - 2) + countNum(index - 3);
	MemoryArray[index-1] = thisVal;
	return thisVal;
}

int main() {
	int T, n;
	cin >> T;

	MemoryArray[0] = 1; MemoryArray[1] = 2; MemoryArray[2] = 4;
	IsUsed[0] = 1; IsUsed[1] = 1; IsUsed[2] = 1;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << countNum(n) << "\n";
	}

	return 0;
}