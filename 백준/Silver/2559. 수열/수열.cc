#include<bits/stdc++.h>

using namespace std;

int N, K;
int num[100001];
int sum[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		if (!i) sum[i] = num[i];
		else sum[i] = sum[i - 1] + num[i];
	}

	int maxi = 0;
	for (int i = K - 1; i < N; i++) {
		if (i == K - 1) maxi = sum[i];
		else maxi = max(maxi, sum[i] - sum[i - K]);
	}

	cout << maxi;
	return 0;
}