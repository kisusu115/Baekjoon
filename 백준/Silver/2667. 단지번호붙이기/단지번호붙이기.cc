#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
vector<int> hnum;
char map[27][27];

void makeBoundary() {
	for (int i = 0; i <= N + 1; i++) {
		map[i][0] = '0'; map[0][i] = '0';
		map[i][N + 1] = '0'; map[N + 1][i] = '0';
	}
}

pair<int, int> direct[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) };

int dfs(int x, int y) {
	map[x][y] = 'X';
	int house = 1;
	for (int i = 0; i < 4; i++) {
		int newX = x + direct[i].first;
		int newY = y + direct[i].second;

		if (map[newX][newY] == '1') {
			map[newX][newY] = 'X';
			house += dfs(newX, newY);
		}
	}
	return house;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	makeBoundary();

	int group = 0;
	cin >> N;
	string ipt;
	for (int i = 1; i <= N; i++) {
		int j = 1;
		cin >> ipt;
		for (char c : ipt) {
			map[i][j] = c;
			j++;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == '1') {
				hnum.push_back(dfs(i, j));
				group++;
			}
		}
	}
	cout << group << "\n";
	sort(hnum.begin(), hnum.end());
	for (int num : hnum) {
		cout << num << "\n";
	}
}