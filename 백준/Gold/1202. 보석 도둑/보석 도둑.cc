#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int BAG[300001];
pair<int, int> JEWEL[300001];
priority_queue<int, vector<int>, less<int>> PQ;

bool compare(pair<int, int> J1, pair<int, int> J2) {
	if (J1.first == J2.first) return J1.second > J2.second;
	else return J1.first < J2.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K; cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int M, V; cin >> M >> V;
		JEWEL[i] = make_pair(M, V);
	}
	for (int i = 0; i < K; i++) cin >> BAG[i];

	sort(BAG, BAG + K);
	sort(JEWEL, JEWEL + N, compare);

	long long max_val = 0;
	int idx = 0;
	for (int i = 0; i < K; i++) {
		while (idx < N && BAG[i] >= JEWEL[idx].first) {
			PQ.push(JEWEL[idx].second);
			idx++;
		}
		if (!PQ.empty()) {
			max_val += PQ.top();
			PQ.pop();
		}
	}
	cout << max_val;
	return 0;
}
