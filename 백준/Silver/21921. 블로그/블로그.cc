#include<bits/stdc++.h>

using namespace std;
vector<int> visitors;
vector<int> visitorsTotal;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, X, ipt;
	cin >> N; cin >> X;

	for (int i = 0; i < N; i++) {
		cin >> ipt;
		visitors.push_back(ipt);
		if (i == 0) visitorsTotal.push_back(ipt);
		else visitorsTotal.push_back(visitorsTotal[i - 1] + ipt);
	}

	int maxVisits = visitorsTotal[X - 1];
	int maxCnt = 1;
	for (int i = 0; i < N-X; i++) {

		int calculatedVisits = visitorsTotal[i + X] - visitorsTotal[i];

		if (maxVisits == calculatedVisits) maxCnt++;
		if (maxVisits < calculatedVisits) {
			maxVisits = calculatedVisits;
			maxCnt = 1;
		}
	}
	if (maxVisits == 0) cout << "SAD";
	else cout << maxVisits << "\n" << maxCnt;
	return 0;
}