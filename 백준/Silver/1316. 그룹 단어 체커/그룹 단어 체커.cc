#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int count = n;

	bool isSold[26] = { false, };

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == s[j + 1])continue;
			if (isSold[int(s[j]) - int('a')] == false) isSold[int(s[j]) - int('a')] = true;
			else if (isSold[int(s[j]) - int('a')] == true) {
				count--;
				break;
			}
		}

		for (int i = 0; i < 26; i++)isSold[i] = false;
	}
	
	cout << count;
	
}