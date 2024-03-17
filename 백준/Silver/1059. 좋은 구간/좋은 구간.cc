#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int retNum(int start, int n, int end) {
    int sub = n - start;
    int sup = end - n;
    int all = end - start + 1;
    return (all * (all - 1) - sup * (sup - 1) - sub * (sub - 1)) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> vt;
    int L;
    cin >> L;
    for (int i = 0; i < L; i++) {
        int ipt;
        cin >> ipt;
        vt.push_back(ipt);
    }
    sort(vt.begin(), vt.end());

    int n;
    cin >> n;
    int start, end;
    bool isfound = false;
    if (vt[0] > n) {
        cout << retNum(1, n, vt[0]-1);
        return 0;
    }
    for (int i=0; i<L; i++){
        if (vt[i] > n) {
            end = vt[i]-1;
            start = vt[i - 1]+1;
            break;
        }
    }
    retNum(start, n, end) == -1 ? cout << 0: cout<< retNum(start, n, end);
    return 0;
}