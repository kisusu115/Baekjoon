#include<iostream>
#include<string.h>

using namespace std;

int triangle[501][501];
int sumarr[501][501];
int N;

int getsum(int x, int y) {
	if (sumarr[x][y] != -1) return sumarr[x][y];
	int ret = max(getsum(x, y + 1) + triangle[x][y], getsum(x + 1, y + 1) + triangle[x][y]);
	if (y == N - 1) ret = triangle[x][y];
	sumarr[x][y] = ret;
	return ret;
}

int main() {
	memset(sumarr, -1, sizeof(int) * 501 * 501);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[j][i];
		}
	}

	cout << getsum(0, 0);
}