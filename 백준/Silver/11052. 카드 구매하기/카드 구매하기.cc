#include<iostream>

using namespace std;

int P[1001];
int M[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	M[1] = P[1];
	for (int i = 2; i <= N; i++) {
		int high = P[i];
		for (int j = 1; j <= i; j++) {
			high = max(high, P[j] + M[i-j]);
		}
		M[i] = high;
	}
	cout << M[N];
	return 0;
}