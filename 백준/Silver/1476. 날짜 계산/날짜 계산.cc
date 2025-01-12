#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int E, S, M;
	cin >> E >> S >> M;

	int num = 1;
	while (1) {
		if ((num - E) % 15 == 0 && (num - S) % 28 == 0 && (num - M) % 19 == 0) break;
		num++;
	}

	cout << num;
	return 0;
}