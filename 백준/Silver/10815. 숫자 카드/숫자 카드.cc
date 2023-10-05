#include<iostream>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		mp[tmp]++;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		cout << mp[tmp] << " ";
	}

}