#include<bits/stdc++.h>

using namespace std;

// way[A][B][S] -> S가 0이면 가로, 1이면 세로, 2이면 대각선
int way[17][17][3];
int house[17][17];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> house[i][j];
		}
	}

	way[1][2][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 3; j <= N; j++) {
			if (house[i][j] == 0) {
				way[i][j][0] = way[i][j - 1][0] + way[i][j - 1][2];

				way[i][j][1] = way[i - 1][j][1] + way[i - 1][j][2];

				if (house[i - 1][j] == 0 && house[i][j - 1] == 0) 
					way[i][j][2] = way[i - 1][j - 1][0] + way[i - 1][j - 1][1] + way[i - 1][j - 1][2];
			}
		}
	}

	cout << way[N][N][0] + way[N][N][1] + way[N][N][2];
	return 0;
}