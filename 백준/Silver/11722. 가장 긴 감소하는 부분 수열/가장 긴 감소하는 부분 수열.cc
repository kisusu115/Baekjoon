#include<iostream>
#include<cmath>

using namespace std;
int arr[1001];
int L[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		int	high = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				high = max(high, L[j] + 1);
			}
		}
		L[i] = high;
	}

	int result = 1;
	for (int i = 0; i < N; i++) {
		result = max(result, L[i]);
	}
	cout << result;
	return 0;
}