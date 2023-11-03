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
	vector<string> vect1;
	vector<string> vect2;

	for (int i = 0; i < n; i++) {
		string ipt1;
		cin >> ipt1;
		vect1.push_back(ipt1);
	}

	for (int i = 0; i < m; i++) {
		string ipt2;
		cin >> ipt2;
		vect2.push_back(ipt2);
	}

	int count = 0;

	sort(vect1.begin(), vect1.end());

	for (int i = 0; i < m; i++) {
		if (binary_search(vect1.begin(), vect1.end(), vect2[i])) count++;
	}

	cout << count;
	return 0;
}