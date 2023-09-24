#include<iostream>
#include<set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	set<int> sat;

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		string ipt;
		cin >> ipt;
		if (ipt == "add") {
			int x;
			cin >> x;
			sat.insert(x);
		}
		else if (ipt == "remove") {
			int x;
			cin >> x;
			if (sat.find(x) != sat.end()) sat.erase(x);
		}
		else if (ipt == "check") {
			int x;
			cin >> x;
			if (sat.find(x) != sat.end()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (ipt == "toggle") {
			int x;
			cin >> x;
			if (sat.find(x) != sat.end()) sat.erase(x);
			else sat.insert(x);
		}
		else if (ipt == "all") {
			sat = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		}
		else if (ipt == "empty") {
			sat.clear();
		}
	}
}