#include <bits/stdc++.h>
using namespace std;

int N, cnt = 0;
int C1[31], C2[31], V[16];

void place(int row) {
    if (row > N) {
        cnt++;
        return;
    }

    for (int col = 1; col <= N; col++) {
        if (C1[row - col + N] == 0 && C2[row + col] == 0 && V[col] == 0) {
            C1[row - col + N] = 1;
            C2[row + col] = 1;
            V[col] = 1;

            place(row + 1);

            C1[row - col + N] = 0;
            C2[row + col] = 0;
            V[col] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    place(1);

    cout << cnt;
    return 0;
}
