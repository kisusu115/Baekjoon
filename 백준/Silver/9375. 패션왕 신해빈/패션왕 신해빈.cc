#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		map<string, int> types;
		for (int i = 0; i < n; i++) {
			string name;
			string type;
			cin >> name >> type;
			if (types.find(type) != types.end()) {
				types[type]++;
			}
			else {
				types.insert({ type, 1 });
			}
		}
		int retVal = 1;
		for (auto it : types) {
			retVal *= (it.second+1);
		}
		cout << retVal - 1 << "\n";
	}
	return 0;
}