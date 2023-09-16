#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int a, b;
    int maxi=0, mini=0;
    cin >> a >> b;

    if (a == b) {
        maxi = a;
        mini = a;
    }
    int tmp = 0;
    if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    for (int i = 1; i <= a - b; i++) {
        if (a % i == 0 && b % i == 0) {
            mini = i;
            maxi = a * b / i;
        }
    }

    cout << mini << endl << maxi << endl;
}