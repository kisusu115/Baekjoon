#include<iostream>

using namespace std;
int coins[101];
int C[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	C[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			C[j] += C[j - coins[i]];
		}
	}
	cout << C[k];
}