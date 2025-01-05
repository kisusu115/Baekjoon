#include<bits/stdc++.h>

using namespace std;
string img[64];

// a는 좌상단 i, b는 좌상단 j, w는 한 변 길이
void dprint(int a, int b, int w) {
	char flag = img[a][b];

	for (int i = a; i < a + w; i++) {
		for (int j = b; j < b + w; j++) {
			if (img[i][j] != flag) {
				cout << '(';
				dprint(a, b, w / 2);
				dprint(a, b + w / 2, w / 2);
				dprint(a + w / 2, b, w / 2);
				dprint(a + w / 2, b + w / 2, w / 2);
				cout << ')';
				return;
			}
		}
	}
	if (flag != -1) cout << flag;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> img[i];
	}

	dprint(0, 0, N);
	return 0;
}