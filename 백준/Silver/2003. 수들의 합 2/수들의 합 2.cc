#include<bits/stdc++.h>

using namespace std;

int N, M;
int n[10001];
int s[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ret = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> n[i];
		if (!i) s[i] = n[i];
		else s[i] = s[i - 1] + n[i];

		for (int j = 0; j < i; j++) {
			int hap = s[i] - s[j];
			if (hap == M) ret++;
		}
	}

	cout << ret;
	return 0;
}