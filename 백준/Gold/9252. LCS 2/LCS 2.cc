#include<bits/stdc++.h>
using namespace std;

int length[1002][1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.length();
    int l2 = s2.length();

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) 
                length[i][j] = length[i - 1][j - 1] + 1;
            else 
                length[i][j] = max(length[i - 1][j], length[i][j - 1]);
        }
    }

    string lcs = "";
    int i = l1, j = l2;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--, j--;
        }
        else if (length[i - 1][j] >= length[i][j - 1])
            i--;
        else 
            j--;
    }

    cout << length[l1][l2] << "\n" << lcs;
    return 0;
}
