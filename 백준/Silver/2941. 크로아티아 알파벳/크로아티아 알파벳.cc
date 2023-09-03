#include<iostream>

using namespace std;

int main() {
	string ip;
	int count = 0;

	cin >> ip;

	for (int i = 0; i < ip.length(); i++) {
		if (ip[i] == 'c' && ip[i + 1] == '=') i++;
		else if (ip[i] == 'c' && ip[i + 1] == '-') i++;
		else if (ip[i] == 'd' && ip[i + 1] == 'z' && ip[i + 2] == '=') i += 2;
		else if (ip[i] == 'd' && ip[i + 1] == '-') i++;
		else if (ip[i] == 'l' && ip[i + 1] == 'j') i++;
		else if (ip[i] == 'n' && ip[i + 1] == 'j') i++;
		else if (ip[i] == 's' && ip[i + 1] == '=') i++;
		else if (ip[i] == 'z' && ip[i + 1] == '=') i++;

		count++;
	}

	cout << count;
}