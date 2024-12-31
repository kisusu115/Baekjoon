#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string ipt; cin >> ipt;

	int cmpIdx = 0; int num = 1;
	while (cmpIdx < ipt.length()) {
		string numStr = to_string(num);
		for (int i = 0; i < numStr.length(); i++) {
			if (ipt[cmpIdx] == numStr[i]) cmpIdx++;
			if (cmpIdx == ipt.length()) {
				cout << num;
				return 0;
			}
		}
		num++;
	}
	return 0;
}