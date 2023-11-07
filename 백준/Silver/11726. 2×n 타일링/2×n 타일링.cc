#include<iostream>
using namespace std;

int P[1000];

int f(int n) {
	int& ret = P[n-1];
	if (ret != -1) {
		return ret;
	}
	ret = f(n - 1) + f(n - 2); 
	if (ret > 10007) {
		ret %= 10007;
	}
	return ret; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fill_n(P, 1000, -1);

	P[0] = 1;
	P[1] = 2;

	int N;
	cin >> N;

	cout << f(N);
}