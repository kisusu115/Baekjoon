#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<char> stk;

	string ipt;
	cin >> ipt;

	for (int i = 0; i < ipt.length(); i++) {
		if (ipt[i] == '*' || ipt[i] == '/') {
			while (!stk.empty()) {
				if (stk.top() == '+'|| stk.top() == '-' || stk.top() == '(') break;
				cout << stk.top();
				stk.pop();
			}
			stk.push(ipt[i]);
		}
		else if (ipt[i] == '+' || ipt[i] == '-') {
			while (!stk.empty()) {
				if (stk.top() == '(') break;
				cout << stk.top();
				stk.pop();
			}
			stk.push(ipt[i]);
		}
		else if (ipt[i] == '(') {
			stk.push(ipt[i]);
		}
		else if (ipt[i] == ')') {
			while (stk.top() != '(') {
				cout << stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else {
			cout << ipt[i];
		}
	}
	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
}