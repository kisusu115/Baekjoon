#include<iostream>
#include<cmath>

using namespace std;

int arr[1001][3] = { 0, };
int retarr[1001][3] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	retarr[0][0] = 0; retarr[0][1] = 0; retarr[0][2] = 0;
	for (int i = 1; i <= N; i++) {
		retarr[i][0] = min(retarr[i - 1][1] + arr[i][0], retarr[i - 1][2] + arr[i][0]);
		retarr[i][1] = min(retarr[i - 1][0] + arr[i][1], retarr[i - 1][2] + arr[i][1]);
		retarr[i][2] = min(retarr[i - 1][0] + arr[i][2], retarr[i - 1][1] + arr[i][2]);
	}

	cout << min(min(retarr[N][0], retarr[N][1]), retarr[N][2]);
}