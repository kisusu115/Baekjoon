#include <iostream>
#include <string.h>

using namespace std;

int xpos[4] = { 1,-1,0,0 };
int ypos[4] = { 0,0,1,-1 };
int ground[50][50] = { 0 };
int visited[50][50] = { 0 };
int m, n, k;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + xpos[i];
        int ny = y + ypos[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        if (ground[nx][ny] && !visited[nx][ny]) {
            visited[nx][ny]++;
            dfs(nx, ny);
        }
    }
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
        int worms = 0;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
            int ix, iy;
            cin >> ix >> iy;
            ground[ix][iy] = 1;
		}
        
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (ground[x][y] && !visited[x][y]) {
                    worms++;
                    visited[x][y]++;
                    dfs(x, y);
                }
            }
        }
		cout << worms << "\n";
        memset(ground, 0, sizeof(ground));
        memset(visited, 0, sizeof(visited));
	}
}