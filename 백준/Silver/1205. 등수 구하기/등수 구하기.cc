#include<bits/stdc++.h>

using namespace std;
vector<int> scores;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, S, P, ipt;
	cin >> N >> S >> P;
	while (N--) {
		cin >> ipt;
		scores.push_back(ipt);
	}

	int rank = 1, check = 0;
	for (int i : scores) {
		if (i > S) rank++;
		if (i == S) check++;
	}
	if (rank + check > P) cout << -1;
	else cout << rank;

	return 0;
}