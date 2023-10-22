#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<long long> vect;
	long long ipt;
	long long ipt2;

	for (int i = 0; i < n; i++) {
		cin >> ipt;
		vect.push_back(ipt);
	}

	sort(vect.begin(), vect.end());

	for (int i = 0; i < m; i++) {
		cin >> ipt2;
		if (binary_search(vect.begin(), vect.end(), ipt2)) {
			cout << lower_bound(vect.begin(), vect.end(), ipt2) - vect.begin() << "\n";
		}
		else {
			cout << -1 << "\n";
			
		}
	}

	return 0;
}