#include<iostream>

using namespace std;
int N;
int arr[1001];
int LM[1001];
int RM[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) {
		int high = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				high = max(high, LM[j] + 1);
			}
		}
		LM[i] = high;
	}
	for (int i = N-1; i >= 0; i--) {
		int high = 1;
		for (int j = N-1; j >= i; j--) {
			if (arr[j] < arr[i]) {
				high = max(high, RM[j] + 1);
			}
		}
		RM[i] = high;
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		result = max(result, LM[i] + RM[i] - 1);
	}
	cout << result;
	return 0;
}