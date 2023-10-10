#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int tmp = n;
    int count = 0;

    while (1) {
        tmp = tmp % 10 * 10 + (tmp % 10 + tmp / 10) % 10;
        count++;
        
        if (tmp == n) {
            cout << count;
            break;
        }
    }

    return 0;
}