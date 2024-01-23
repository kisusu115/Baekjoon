#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n, r, c;
    cin >> n >> r >> c;
    r++;
    c++;
    int count = 0;
    
    for (int ind = 0; ind < 15; ind++) {
        for (int i = n - 1; i >= 0; i--) {
            if (r > pow(2, i)) {
                count += pow(2, i) * pow(2, i + 1);
                r -= pow(2, i);
                break;
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (c > pow(2, j)) {
                count += pow(2, j) * pow(2, j);
                c -= pow(2, j);
                break;
            }
        }
    }
    cout << count;
}