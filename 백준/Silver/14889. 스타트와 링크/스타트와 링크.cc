#include<bits/stdc++.h>

using namespace std;

int N;
int S[21][21];

bool selected[21];

int minGap = INT_MAX;

void dfs(int idx, int people) {
	if (people == N / 2) {
		int startTeam = 0, linkTeam = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (selected[i] && selected[j]) startTeam += S[i][j];
				if (!selected[i] && !selected[j]) linkTeam += S[i][j];
			}
		}

		minGap = min(minGap, abs(startTeam - linkTeam));
		return;
	}

	for (int i = idx; i <= N; i++) {
		selected[i] = true;
		dfs(i+1, people + 1);
		selected[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	}

	selected[1] = true;
	dfs(2, 1);

	cout << minGap;
	return 0;
}