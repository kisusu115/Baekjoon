#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[41][2];
    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 1;

    for (int j = 2; j <= 40; j++) {
        arr[j][0] = arr[j - 1][0] + arr[j - 2][0];
        arr[j][1] = arr[j - 1][1] + arr[j - 2][1];
    }
    for (int i = 0; i < n; i++) {
        int ipt;
        cin >> ipt;
        
        cout << arr[ipt][0] << " " << arr[ipt][1] << "\n";
    }
    return 0;
}