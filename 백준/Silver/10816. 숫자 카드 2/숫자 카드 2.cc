#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (mp.find(tmp) == mp.end()) {
			mp[tmp] = 1;
		}
		else {
			mp[tmp]++;
		}
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		if (mp.find(tmp) == mp.end()) {
			cout << 0 << " ";
		}
		else {
			cout << mp[tmp] << " ";
		}
	}

}