#include<iostream>
#include<string.h>
#include<queue>

using namespace std;
int N, K;
int T[100001];
queue<int> q;

void bfs(int N) {
	T[N] = 0;
	q.push(N);

	while (!q.empty()) {
		int top = q.front();
		q.pop();
		if (top >= 1 && T[top - 1] == -1) {
			T[top - 1] = T[top] + 1;
			q.push(top - 1);
		}
		if (top <= 100000 && T[top + 1] == -1) {
			T[top + 1] = T[top] + 1;
			q.push(top + 1);
		}
		if (top <= 50000 && T[2 * top] == -1) {
			T[2 * top] = T[top] + 1;
			q.push(2 * top);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(T, -1, sizeof(int) * 100001);

	cin >> N >> K;
	bfs(N);
	cout << T[K];
}