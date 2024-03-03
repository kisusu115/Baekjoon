#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> vect;
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int ipt;
		cin >> ipt;
		vect.push_back(ipt);
	}

	sort(vect.begin(), vect.end());

	cout << vect[0] * vect[vect.size() - 1];
}