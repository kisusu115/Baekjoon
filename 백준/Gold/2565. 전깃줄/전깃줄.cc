#include<iostream>
#include<algorithm>

using namespace std;
pair<int, int> lines[101];
int arr[101];
int DP[101];	// DP[N]은 N에서 끝나는 부분수열의 최대 길이

bool compare(pair<int, int> L1, pair<int, int> L2) {
	return L1.first < L2.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int ipt1, ipt2;
		cin >> ipt1 >> ipt2;
		lines[i] = make_pair(ipt1, ipt2);
	}

	sort(lines, lines + N, compare);

	DP[0] = 1;
	for (int i = 0; i < N; i++) arr[i] = lines[i].second;
	for (int i = 1; i < N; i++) {
		int maxi = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				maxi = max(maxi, DP[j] + 1);
			}
		}
		DP[i] = maxi;
	}
	int result = 0;
	for (int i = 0; i < N; i++) result = max(result, DP[i]);
	cout << N - result;
	return 0;
}