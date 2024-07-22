#include<iostream>

using namespace std;

long long calculated[101] = {0,};

long long getsum(int a) {
	if (calculated[a] != 0) return calculated[a];
	long long ret = getsum(a - 2) + getsum(a - 3);
	calculated[a] = ret;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	calculated[0] = 1;
	calculated[1] = 1;
	calculated[2] = 1;

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << getsum(n-1) << "\n";
	}

	return 0;
}