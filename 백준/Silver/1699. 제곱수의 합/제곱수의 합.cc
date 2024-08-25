#include<iostream>
#include<cmath>

using namespace std;
int C[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	for (int i = 0; i <= N; i++) {
		C[i] = i;
		for (int j = 1; j * j <= i; j++) {
			C[i] = min(C[i], C[i - j * j] + 1);
		}
	}
	cout << C[N];
	return 0;
}