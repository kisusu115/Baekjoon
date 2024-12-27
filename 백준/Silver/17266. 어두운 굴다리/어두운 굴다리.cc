#include<bits/stdc++.h>

using namespace std;
vector<int> Xs;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, ipt, maxWidth = -1, height; cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> ipt;
		Xs.push_back(ipt);
	}
	for (int i = 1; i < M; i++) {
		maxWidth = max(maxWidth, Xs[i] - Xs[i - 1]);
	}
	height = (maxWidth + 1) / 2;
	height = max(height, Xs[0]);
	height = max(height, N - Xs[M - 1]);

	cout << height;
	return 0;
}