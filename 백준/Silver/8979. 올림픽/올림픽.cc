#include<bits/stdc++.h>

using namespace std;
int medal[1001][4];

bool medalCmp(int v1[4], int v2[4]) {
	if (v1[1] != v2[1]) return v1[1] < v2[1];
	if (v1[2] != v2[2]) return v1[2] < v2[2];
	return v1[3] < v2[3];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> medal[i][0] >> medal[i][1] >> medal[i][2] >> medal[i][3];
	}

	int idx = -1;
	for (int i = 0; i < N; i++) {
		if (medal[i][0] == K) {
			idx = i; break;
		}
	}

	int rank = 1;
	for (int i = 0; i < N; i++) {
		if (medalCmp(medal[idx], medal[i])){
			rank++;
		}
	}
	cout << rank;

	return 0;
}