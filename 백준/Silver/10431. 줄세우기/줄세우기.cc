#include<bits/stdc++.h>

using namespace std;
int height[20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int backwards = 0;
		int tNum; cin >> tNum;
		for (int i = 0; i < 20; i++) cin >> height[i];
		for (int i = 1; i < 20; i++) {
			for (int j = 0; j < i; j++) {
				if (height[i] < height[j]) backwards++;
			}
		}
		cout << tNum << " " << backwards << "\n";
	}
	return 0;
}