#include<iostream>

using namespace std;
int map[52][52];
int visited[52][52];
pair<int, int> direct[8] = { make_pair(0, 1), make_pair(1, 1), make_pair(1, 0), make_pair(1, -1),
							make_pair(0, -1), make_pair(-1, -1), make_pair(-1, 0), make_pair(-1, 1) };

void dfs(int w, int h) {
	visited[h][w] = 1;
	for (int i = 0; i < 8; i++) {
		int newH = h + direct[i].first;
		int newW = w + direct[i].second;
		if (map[newH][newW] == 1 && visited[newH][newW] == 0) {
			dfs(newW, newH);
		}
	}
}

void makeBoundary(int w, int h) {
	for (int i = 0; i <= w + 1; i++) {
		for (int j = 0; j <= h + 1; j++) {
			map[0][i] = 0; map[h+1][i] = 0;
			map[j][0] = 0; map[j][w+1] = 0;
		}
	}
}

void init(int w, int h) {
	for (int j = 1; j <= h; j++) {
		for (int i = 1; i <= w; i++) {
			map[j][i] = 0;
			visited[j][i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		int w, h;
		cin >> w >> h;
		if (w <= 0 || h <= 0) break;
		makeBoundary(w, h);
		for (int j = 1; j <= h; j++) {
			for (int i = 1; i <= w; i++) {
				cin >> map[j][i];
			}
		}

		int cnt = 0;
		for (int j = 1; j <= h; j++) {
			for (int i = 1; i <= w; i++) {
				if (map[j][i] == 1 && visited[j][i] == 0) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << "\n";

		init(w, h);
	}

	return 0;
}