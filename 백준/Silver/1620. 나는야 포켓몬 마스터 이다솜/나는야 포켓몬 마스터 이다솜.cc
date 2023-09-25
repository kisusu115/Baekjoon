#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> vect;
	map<string, int> ma;
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;

		vect.push_back(name);
		ma.insert({ name, i });
	}

	for (int i = 0; i < m; i++) {
		string ipt;
		cin >> ipt;
		if ('a'<=ipt[0]&&'z'>=ipt[ipt.length()] || 'A' <= ipt[0] && 'Z' >= ipt[ipt.length()]) {
			cout << ma[ipt] << "\n";
		}
		else {
			int tmp = stoi(ipt);
			cout << vect[tmp - 1] << "\n";
		}
	}
}