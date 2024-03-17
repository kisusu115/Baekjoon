#include <iostream>
#include <vector>

using namespace std;

int main() {
    int std[10];
    int ft[42];
    int ipt;

    for (int i = 0; i < 42; i++) {
        ft[i] = 0;
    }

    for (int i = 0; i < 10; i++) {
        cin >> ipt;
        int n;
        n = ipt % 42;
        for (int j = 0; j < 42; j++) {
            if (n == j) {
                ft[j]++;
            }
        }
    }
    int count=0;
    for (int i = 0; i < 42; i++) {
        if (ft[i] != 0) {
            count++;
        }
    }

    cout << count;
}
