#include<bits/stdc++.h>

using namespace std;
string HP;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, cnt = 0;
	cin >> n >> k;
	cin >> HP;
	for (int i = 0; i < HP.size(); i++) {
		if (HP[i] == 'P') {
			for (int j = i - k; j <= i + k; j++) {
				if (j >= 0 && j < HP.size() && HP[j] == 'H') {
					HP[j] = 'X'; cnt++; break;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}