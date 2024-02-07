#include <iostream>
using namespace std;

int numArr[1000] = { 0 };
int stairArr[1000] = { 0 };

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int inputNum;
		cin >> inputNum;
		numArr[i] = inputNum;
	}

	stairArr[0] = 1;

	for (int i = 0; i < N; i++) {
		if (stairArr[i]!=0) continue;
		int maxStairVal = -1;
		for (int j = 0; j < i; j++) {
			if ((numArr[j] < numArr[i]) && (stairArr[j] > maxStairVal)) {
				maxStairVal = stairArr[j];
				stairArr[i] = maxStairVal + 1;
			}
		}
		if (stairArr[i] == 0) stairArr[i] = 1;
	}

	int answer = -1;
	for (int i = 0; i < N; i++) {
		if (stairArr[i] > answer) answer = stairArr[i];
	}
	cout << answer;

	return 0;
}