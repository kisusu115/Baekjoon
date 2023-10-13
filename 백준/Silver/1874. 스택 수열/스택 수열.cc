#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    stack<int> stk;
    vector<char> ans;

    int ipt;
    int stknum = 0;
    bool Error = false;

    stk.push(stknum);
    stknum++;

    for (int i = 0; i < n; i++) {
        cin >> ipt;

        while (stk.top() < ipt) {
            stk.push(stknum);
            stknum++;
            ans.push_back('+');
        }
        if (stk.top() == ipt) {
            stk.pop();
            ans.push_back('-');
        }
        else {
            Error = true;
        }
    }
    if (Error) {
        cout << "NO" << '\n';
    }
    else {
        for (auto a : ans) {
            cout << a << '\n';
        }
    }
}