#include<iostream>

using namespace std;

long long stair[101][10] = {0,};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i < 10; i++) stair[0][i] = 1;
	stair[0][0] = 0;
	for (int i = 1; i < N; i++) {
		stair[i][0] = stair[i - 1][1];
		stair[i][1] = (stair[i - 1][0] + stair[i - 1][2]) % 1000000000;
		stair[i][2] = (stair[i - 1][1] + stair[i - 1][3]) % 1000000000;
		stair[i][3] = (stair[i - 1][2] + stair[i - 1][4]) % 1000000000;
		stair[i][4] = (stair[i - 1][3] + stair[i - 1][5]) % 1000000000;
		stair[i][5] = (stair[i - 1][4] + stair[i - 1][6]) % 1000000000;
		stair[i][6] = (stair[i - 1][5] + stair[i - 1][7]) % 1000000000;
		stair[i][7] = (stair[i - 1][6] + stair[i - 1][8]) % 1000000000;
		stair[i][8] = (stair[i - 1][7] + stair[i - 1][9]) % 1000000000;
		stair[i][9] = stair[i - 1][8] % 1000000000;
	}
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += stair[N-1][i];
	}
	cout << sum % 1000000000;

	return 0;
}