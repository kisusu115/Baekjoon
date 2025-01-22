#include<bits/stdc++.h>

using namespace std;

int N; 
int mx = -1000000001;
int mn = 1000000001;
int num[11];
int ret[11];
int op[4];

void dfs(int depth) {
	if (depth == N) {
		mx = max(mx, ret[depth - 1]);
		mn = min(mn, ret[depth - 1]);
		return;
	}
	if (depth == 0) {
		ret[0] = num[0];
		dfs(depth + 1);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (op[i] > 0) {
				op[i]--;
				if (i == 0) ret[depth] = ret[depth - 1] + num[depth];
				else if (i == 1) ret[depth] = ret[depth - 1] - num[depth];
				else if (i == 2) ret[depth] = ret[depth - 1] * num[depth];
				else if (i == 3) ret[depth] = ret[depth - 1] / num[depth];
				dfs(depth + 1);
				op[i]++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> op[i];

	dfs(0);
	cout << mx << "\n" << mn;

	return 0;
}