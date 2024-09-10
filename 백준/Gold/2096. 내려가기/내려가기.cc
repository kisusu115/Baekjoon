#include<iostream>
#include<algorithm>

using namespace std;
int arr[2][3];
int HDP[2][3];
int LDP[2][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	int idx;
	for (int turn = 0; turn < N; turn++) {
		idx = turn % 2;
		cin >> arr[idx][0] >> arr[idx][1] >> arr[idx][2];
		if (idx == 1) {
			HDP[1][0] = max(HDP[0][0], HDP[0][1]) + arr[1][0];
			LDP[1][0] = min(LDP[0][0], LDP[0][1]) + arr[1][0];

			HDP[1][1] = max(max(HDP[0][0], HDP[0][1]), HDP[0][2]) + arr[1][1];
			LDP[1][1] = min(min(LDP[0][0], LDP[0][1]), LDP[0][2]) + arr[1][1];

			HDP[1][2] = max(HDP[0][2], HDP[0][1]) + arr[1][2];
			LDP[1][2] = min(LDP[0][2], LDP[0][1]) + arr[1][2];
		}
		else {
			HDP[0][0] = max(HDP[1][0], HDP[1][1]) + arr[0][0];
			LDP[0][0] = min(LDP[1][0], LDP[1][1]) + arr[0][0];

			HDP[0][1] = max(max(HDP[1][0], HDP[1][1]), HDP[1][2]) + arr[0][1];
			LDP[0][1] = min(min(LDP[1][0], LDP[1][1]), LDP[1][2]) + arr[0][1];

			HDP[0][2] = max(HDP[1][2], HDP[1][1]) + arr[0][2];
			LDP[0][2] = min(LDP[1][2], LDP[1][1]) + arr[0][2];
		}
	}
	cout << max(max(HDP[idx][0], HDP[idx][1]), HDP[idx][2]) << " " << min(min(LDP[idx][0], LDP[idx][1]), LDP[idx][2]);
	return 0;
}