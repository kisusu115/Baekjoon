#include<bits/stdc++.h>

using namespace std;

int N, M;
string ipt;
set<string> keywords;
vector<string> parts;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;

	while (N--) {
		cin >> ipt;
		keywords.insert(ipt);
	}

	while (M--) {
		cin >> ipt; 
		int idx = 0;
		string part = "";
		while (idx != -1) {
			idx = ipt.find(",");

			if (idx == -1) part = ipt;
			else part = ipt.substr(0, idx);

			keywords.erase(part);
			ipt.erase(0, idx + 1);
		}

		cout << keywords.size() << "\n";
	}

	return 0;
}