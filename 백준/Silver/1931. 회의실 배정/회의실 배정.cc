#include<iostream>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	int n;
	cin >> n;
	pair<int,int> P[100000];

	for (int i = 0; i < n; i++) {
		cin >> P[i].first >> P[i].second;
	}

	sort(P, P + n, compare);

	int start = P[0].first;
	int end = P[0].second;
	bool isEnd = false;
	int count = 1;
	int currentIndex = 0;

	while (!isEnd) {
		isEnd = true;
		for (int i = currentIndex+1; i < n; i++) {
			if (P[i].first >= end) {
				start = P[i].first;
				end = P[i].second;
				currentIndex = i;
				count++;
				isEnd = false;
				break;
			}
		}
	}
	cout << count;
	return 0;
}