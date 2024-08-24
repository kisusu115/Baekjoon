#include<iostream>

using namespace std;
int arr[1001];
int M[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		M[i] = arr[i];
		int high = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				high = max(high, M[j]);
			}
		}
		M[i] += high;
		result = max(result, M[i]);
	}

	cout << result;
	return 0;
}