#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> s1, pair<int, int> s2) {
	if (s1.first == s2.first) {
		return s1.second < s2.second;
	}
	return s1.first < s2.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> vect;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vect.push_back(make_pair(x, y));
	}

	sort(vect.begin(), vect.end(), compare);

	for (auto a : vect) {
		cout << a.first << " " << a.second << "\n";
	}
}