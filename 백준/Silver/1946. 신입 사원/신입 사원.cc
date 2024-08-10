#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int T;

bool compare(pair<int, int>p1, pair<int, int>p2) {
	return p1.first < p2.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int S, M;
		vector<pair<int, int>> v;

		for (int i = 0; i < N; i++) {
			cin >> S >> M;
			v.push_back(make_pair(S, M));
		}

		sort(v.begin(), v.end(), compare);

		int max_sec = v[0].second;
		int max_idx = 0;
		int cnt = 1;
		for (int i = 1; i < N; i++) {
			if (max_sec > v[i].second) {
				max_sec = v[i].second;
				max_idx = i;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}