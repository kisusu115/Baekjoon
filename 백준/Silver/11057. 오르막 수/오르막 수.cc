#include<iostream>

using namespace std;

int arr[1001][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i <= 9; i++) {
		arr[1][i] = 1;
	}
	for (int length= 2; length <= N; length++) {
		for (int i = 0; i <= 9; i++) {
			int sum = 0;
			for (int j = 0; j <= i; j++) {
				sum += arr[length - 1][j];
			}
			arr[length][i] = sum % 10007;
		}
	}
	int result = 0;
	for (int i = 0; i <= 9; i++) result += arr[N][i];
	cout << result % 10007;
	return 0;
}