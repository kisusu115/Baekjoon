#include<iostream>
#include<algorithm>
#define INF 987654321

using namespace std;

int P[1000000];

int mk1(int k) {
	int& ret = P[k - 1];
	if (ret != INF) return ret;
	if (k % 3 == 0) {
		ret = min(ret, mk1(k / 3) + 1);
	}
	if (k % 2 == 0) {
		ret = min(ret, mk1(k / 2) + 1);
	}
	ret = min(ret, mk1(k - 1) + 1);
	return ret;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill_n(P, 1000000, INF);
	P[0] = 0;
	int n;
	cin >> n;

	cout << mk1(n);
}