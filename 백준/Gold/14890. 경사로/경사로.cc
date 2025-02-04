#include<bits/stdc++.h>

using namespace std;

int N, L;
int M[100][100];

bool valid(int m[100]) {
	int used[100] = { 0, };
	for (int i = 0; i < N; i++) {
		if (!i) continue;
		if (m[i] == m[i - 1]) continue;
		else if (m[i] + 1 == m[i - 1]) {
			for (int b = 1; b <= L - 1; b++) {
				if (i + b >= N) return false;
				if (m[i] != m[i + b]) return false;
			}
			for (int j = i; j <= i + L - 1; j++) used[j] = 1;
		}
		else if (m[i] - 1 == m[i - 1]) {
			for (int b = 1; b <= L; b++) {
				if (i - b < 0) return false;
				if (m[i] - 1 != m[i - b]) return false;
				if (used[i - b]) return false;
			}
		}
		else return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> M[i][j];
		}
	}

	int Mdup[100] = { 0, };
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Mdup[j] = M[i][j];
		}
		if (valid(Mdup)) ret++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Mdup[j] = M[j][i];
		}
		if (valid(Mdup)) ret++;
	}

	cout << ret;
	return 0;
}