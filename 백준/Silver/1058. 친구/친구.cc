#include<bits/stdc++.h>

using namespace std;

queue<int> q;
bool friends[51][51];
bool two_f[51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	string line;
	for (int i = 0; i < N; i++) {
		cin >> line;

		for (int j = 0; j < N; j++) {
			friends[i][j] = (line[j] == 'Y');
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (friends[i][j] == 1) {
				two_f[i][j] = 1;
				q.push(j);
			}
		}
		while (!q.empty()) {
			int num = q.front();
			for (int j = 0; j < N; j++) {
				if (friends[num][j] == 1) {
					two_f[i][j] = 1;
				}
			}
			q.pop();
		}
	}

	int ret = -1;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if(i != j) sum += two_f[i][j];
		}
		ret = max(ret, sum);
	}
	
	cout << ret;
	return 0;
}