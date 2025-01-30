#include<bits/stdc++.h>

using namespace std;

int N, M;
int num[1000001];
long long sum[1000001];
int rest[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	rest[0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		sum[i] = sum[i - 1] + num[i];
		rest[sum[i] % M]++;
	}

	long long ret = 0;
	for (int i = 0; i < M; i++) {
		long long restCnt = rest[i];
		ret += restCnt * (restCnt - 1) / 2;
	}

	cout << ret;
	return 0;
}