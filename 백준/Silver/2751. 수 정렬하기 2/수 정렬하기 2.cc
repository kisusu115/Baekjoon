#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> vect;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int ipt;
		cin >> ipt;
		vect.push_back(ipt);
	}

	sort(vect.begin(), vect.end());

	for (auto a : vect) cout << a << "\n";
}