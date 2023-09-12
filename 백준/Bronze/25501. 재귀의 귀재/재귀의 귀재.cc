#include <iostream>
#include <string.h>

using namespace std;

class Test {
public:
    string ipt;
    int ipt_rcount = 0;
};

int recursion(Test& t, int l, int r) {
    t.ipt_rcount++;
    if (l >= r) return 1;
    else if (t.ipt[l] != t.ipt[r]) return 0;
    else return recursion(t, l + 1, r - 1);
}

int isPalindrome(Test& t) {
    return recursion(t, 0, t.ipt.length()-1);
}

int main() {
    int T;
    cin >> T;

    Test t[1000];

    for (int i = 0; i < T; i++) {
        cin >> t[i].ipt;
        cout << isPalindrome(t[i]) << " " << t[i].ipt_rcount << endl;
    }
}