#include<bits/stdc++.h>

using namespace std;

string S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> S;
	int n0 = 0; int n1 = 0;
	for (char c : S) {
		if (c == '0') n0++;
		if (c == '1') n1++;
	}
	int c0 = n0 / 2; int c1 = n1 / 2;

	int idx = 0;
	while (1) {
		if (c1 == 0) break;
		if (c1 > 0 && S[idx] == '1') {
			S.erase(idx, 1);
			c1--;
		}
		else idx++;
	}

	idx = S.size() - 1;
	while (1) {
		if (c0 == 0) break;
		if (c0 > 0 && S[idx] == '0') {
			S.erase(idx, 1);
			idx--;
			c0--;
		}
		else idx--;
	}
	
	cout << S;
	return 0;
}