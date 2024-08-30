#include<iostream>

using namespace std;
int arr[100001][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	arr[0][0] = 1; arr[0][1] = 0;
	for (int i = 1; i <= N; i++) {
		arr[i][0] = (arr[i - 1][0] + arr[i - 1][1]) % 9901;
		arr[i][1] = (arr[i - 1][0] * 2 + arr[i - 1][1]) % 9901;
	}

	cout << (arr[N][0] + arr[N][1]) % 9901;
	return 0;
}