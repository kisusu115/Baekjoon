#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(string s1, string s2) {
	if (s1.length() == s2.length()) return s1 < s2;
	else return s1.length() < s2.length();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<string> vect;

	for (int i = 0; i < n; i++) {
		string ipt;
		cin >> ipt;
		if (vect.empty()) vect.push_back(ipt);
		else {
			if (find(vect.begin(), vect.end(), ipt) == vect.end()) {
				vect.push_back(ipt);
			}
		}
	}

	sort(vect.begin(), vect.end(), compare);
	for (auto a : vect) {
		cout << a << "\n";
	}
}