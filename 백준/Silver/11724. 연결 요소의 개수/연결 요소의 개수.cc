#include<iostream>
#include<string.h>

using namespace std;

int N, M;
int visited[1000] = { 0 };
int Arr[1000][1000] = { 0 };
int idx[1000] = { 0 };
int answer = 0;

void dfs(int n) {
	if (visited[n] == 1) return;
	visited[n] = 1;

	int i = 0;
	while (Arr[n][i] != 0) {
		dfs(Arr[n][i]);
		i++;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int p1, p2;
		cin >> p1 >> p2;

		Arr[p1][idx[p1]++] = p2;
		Arr[p2][idx[p2]++] = p1;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			answer++;
			dfs(i);
		}
	}

	cout << answer;
}