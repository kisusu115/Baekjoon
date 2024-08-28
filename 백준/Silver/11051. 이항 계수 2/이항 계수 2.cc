#include<iostream>

using namespace std;
int arr[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j == 0 || i == j) arr[i][j] = 1;
			else arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007;
		}
	}

	cout << arr[N][K];

	return 0;
}