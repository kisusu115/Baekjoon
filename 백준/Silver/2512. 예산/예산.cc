#include<bits/stdc++.h>

using namespace std;
vector<int> budgets;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ipt, N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ipt;
		budgets.push_back(ipt);
	}
	int boundary; cin >> boundary;

	sort(budgets.begin(), budgets.end());

	int sum = 0;
	int limitIdx = -1;
	int maxBudget = budgets[N - 1];
	for (int i = 0; i < budgets.size(); i++) {
		int nowBudget = sum + (N - i) * budgets[i];
		if (nowBudget > boundary) {
			limitIdx = i;
			break;
		}
		else sum += budgets[i];
	}
	if (limitIdx != -1) maxBudget = (boundary - sum) / (N - limitIdx);
	cout << maxBudget;
	return 0;
}