#include<iostream>
#include<algorithm>
#include<string.h>
#include<limits.h>

using namespace std;
int arr[501];
int SUM[501][501];	//SUM[S][E]는 인덱스 S부터 E 까지 파일 크기의 합
int DP[501][501];	//DP[S][E]는 인덱스 S부터 E 까지 파일 합쳤을 때의 최소비용

void init() {
	for (int i = 0; i < 501; i++) arr[i] = 0;
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			SUM[i][j] = 0;
			DP[i][j] = INT_MAX;
		}
	}
}

int LS(int st, int ed) {
	if (DP[st][ed] != INT_MAX) return DP[st][ed];
	if (st == ed) return DP[st][ed] = 0;
	int MinCost = INT_MAX;
	for (int i = st; i < ed; i++) {
		MinCost = min(MinCost, LS(st, i) + LS(i + 1, ed) + SUM[st][ed]);
	}
	return DP[st][ed] = MinCost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		init();
		int K; cin >> K;
		for (int i = 0; i < K; i++) cin >> arr[i];
		SUM[0][0] = arr[0];
		for (int i = 1; i < K; i++) {
			for (int j = 0; j <= i; j++) {
				SUM[j][i] = SUM[j][i - 1] + arr[i];
			}
		}
		if (T == 0) cout << LS(0, K - 1);
		else cout << LS(0, K - 1) << "\n";
	}
	return 0;
}