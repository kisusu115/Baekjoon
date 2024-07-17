#include<iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int arr[300][2] = { 0, };
	int N;
	cin >> N;
	int stair[300];
	for (int i = 0; i < N; i++) {
		cin >> stair[i];
	}
	arr[0][0] = stair[0];
	arr[0][1] = stair[0];
	arr[1][0] = stair[0] + stair[1];
	arr[1][1] = stair[1];

	for (int i = 2; i < N; i++) {
		arr[i][0] = arr[i - 1][1] + stair[i];
		arr[i][1] = max(arr[i - 2][0] + stair[i], arr[i - 2][1] + stair[i]);
	}

	cout << max(arr[N - 1][0], arr[N - 1][1]);
	return 0;
}