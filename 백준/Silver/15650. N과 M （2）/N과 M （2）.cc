#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int A[8] = { 0 };

void dfs(int x, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << A[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = x + 1; i <= n; i++) {
		A[cnt] = i;
		dfs(i, cnt + 1);
	}
}

int main() {
	cin >> n >> m;

	dfs(0, 0);
}