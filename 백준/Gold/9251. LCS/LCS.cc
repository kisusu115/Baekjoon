#include<iostream>
#include<string.h>

using namespace std;

int dp[1002][1002] = {0, };
 
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
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[l1][l2];
	return 0;
}