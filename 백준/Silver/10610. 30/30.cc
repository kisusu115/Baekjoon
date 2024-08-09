#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string ipt;
	cin >> ipt;
	int sum = 0;
	for (char c : ipt) {
		sum += (int)c - 48;
		v.push_back((int)c - 48);
	}

	sort(v.begin(), v.end(), compare);

	if (sum % 3 == 0 && v[v.size()-1] == 0) {
		for (int num : v) cout << num;
	}
	else cout << -1;

	return 0;
}