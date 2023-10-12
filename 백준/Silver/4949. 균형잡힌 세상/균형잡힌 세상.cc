#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;

    while (getline(cin, str)) {
        if (str == ".") break;
        stack<char> stk;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[') {
                stk.push(str[i]);
            }
            else if (str[i] == ')') {
                if (stk.empty()) {
                    stk.push(str[i]);
                }
                else if (stk.top() == '(') {
                    stk.pop();
                }
                else {
                    stk.push(str[i]);
                }
            }
            else if (str[i] == ']') {
                if (stk.empty()) {
                    stk.push(str[i]);
                }
                else if (stk.top() == '[') {
                    stk.pop();
                }
                else {
                    stk.push(str[i]);
                }
            }
        }
        if (stk.empty()) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }
    
}