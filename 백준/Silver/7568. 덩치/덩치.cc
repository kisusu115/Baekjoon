#include<bits/stdc++.h>

using namespace std;
pair<int, int> WH[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> WH[i].first;
		cin >> WH[i].second;
	}
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (WH[i].first < WH[j].first && WH[i].second < WH[j].second) cnt++;
		}
		cout << cnt << " ";
	}

	return 0;
}