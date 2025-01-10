#include <bits/stdc++.h>
using namespace std;

int N;
int graph[101][101];
bool visited[101];

int find(int start, int target, int chon) {
    visited[start] = true;
    if (start == target) return chon;

    for (int i = 1; i <= N; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            int result = find(i, target, chon + 1);
            if (result != -1) return result;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(graph, 0, sizeof(graph));
    memset(visited, false, sizeof(visited));

    cin >> N;
    int per1, per2; cin >> per1 >> per2;

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int ipt1, ipt2;
        cin >> ipt1 >> ipt2;
        graph[ipt1][ipt2] = 1;
        graph[ipt2][ipt1] = 1;
    }

    cout << find(per1, per2, 0);

    return 0;
}
