#include<iostream>
#include<cmath>

using namespace std;

string made[13];

string write_line(int n) {
	if (n == 0) return "-";
	if (made[n] != "") return made[n];

	string ret_str = "";
	ret_str += write_line(n - 1);
	for (int i = 0; i < pow(3, n - 1); i++) {
		ret_str += " ";
	}
	ret_str += write_line(n - 1);
	made[n] = ret_str;
	return made[n];
}

int main() {
	int ipt;
	while (cin >>ipt){
		cout << write_line(ipt) << "\n";
	}
	return 0;
}