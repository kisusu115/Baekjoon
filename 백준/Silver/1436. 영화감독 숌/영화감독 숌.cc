#include<bits/stdc++.h>

using namespace std;
int num = 666;
int order = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	while (1) {
		string numStr = to_string(num);
		for (int i = 0; i < numStr.length() - 2; i++) {
			if (numStr[i] == '6' && numStr[i + 1] == '6' && numStr[i + 2] == '6') {
				order++;
				if (order == N) {
					cout << num;
					return 0;
				}
				break;
			}
		}
		num++;
	}

	return 0;
}
