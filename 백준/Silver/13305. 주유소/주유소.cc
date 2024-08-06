#include<iostream>
#include<vector>

using namespace std;
vector<int> road;
vector<int> price;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int ipt; cin >> ipt;
		road.push_back(ipt);
	}
	for (int i = 0; i < N; i++) {
		int ipt; cin >> ipt;
		price.push_back(ipt);
	}
	long long total = 0;
	int minP = price[0];
	for (int i = 0; i < N; i++) {
		if (minP > price[i]) minP = price[i];
		total += minP * road[i];
	}

	cout << total;
	return 0;
}