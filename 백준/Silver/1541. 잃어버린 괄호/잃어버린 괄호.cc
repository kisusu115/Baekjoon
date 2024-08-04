#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<int> put;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string ipt;
	cin >> ipt;
	int idx = -1; int op = 0; int ed = 0;
	bool minus = false;

	for (char c : ipt) {
		idx++; ed++;
		if (c == '+' || c == '-') {
			string cut = ipt.substr(op, ed-1);
			op = idx + 1; ed = 0;

			int newnum = stoi(cut);
			if (minus) put.push_back(newnum * -1);
			else put.push_back(newnum);

			if (c == '-') minus = true;
		}
		if (idx == ipt.length() - 1) {
			string cut = ipt.substr(op);

			int newnum = stoi(cut);
			if (minus)put.push_back(newnum * -1);
			else put.push_back(newnum);
		}
	}
	int sum = 0;
	for (int i = 0; i < put.size(); i++) {
		sum += put[i];
	}
	cout << sum;
	return 0;
}