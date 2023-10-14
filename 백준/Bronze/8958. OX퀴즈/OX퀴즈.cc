#include <iostream>
#include <string>
using namespace std;

int main() {
	int ipt;
	string str;

	cin >> ipt;
	for (int j = 0; j < ipt; j++) {
		cin >> str;
		int sum, tmp;
		sum = tmp = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'O') tmp++;
			else tmp = 0;
			sum += tmp;
		}
		cout << sum << '\n';
	}
}