#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N, M ,tmp;
    long long answer, sub;

    cin >> T;

    while(T--) {
        answer = 1;
        tmp = 1;
        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            answer *= M--;
            answer /= tmp++;
        }

        cout << answer << "\n";
    }
}