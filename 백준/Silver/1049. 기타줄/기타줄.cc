#include<iostream>
#include<algorithm>

using namespace std;

int m6[51];
int m1[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> m6[i] >> m1[i];
	}

	sort(m6, m6 + M); sort(m1, m1 + M);
	int min6 = m6[0]; int min1 = m1[0];

	if (min6 == 0 || min1 == 0) {
		cout << 0;
		return 0;
	}

	string type;
	if (min6 <= min1 * (N % 6)) type = "전부 묶음";
	else if (min6 > min1 * 6) type = "전부 낱개";
	else type = "최대 묶음 후 낱개";

	if (type == "전부 묶음") cout << (N + 5) / 6 * min6;
	else if (type == "전부 낱개") cout << N * min1;
	else if (type == "최대 묶음 후 낱개") cout << N / 6 * min6 + N % 6 * min1;

	return 0;
}