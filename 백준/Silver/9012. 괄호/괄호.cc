#include<iostream>
#include<stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	stack<char> stk1;

	for (int i = 0; i < n; i++) {
		string ipt;
		cin >> ipt;
		for (int j = 0; j < ipt.length(); j++) {
			if (!stk1.empty()) {
				if (stk1.top() == '(' && ipt[j] == ')') {
					stk1.pop();
				}
				else {
					stk1.push(ipt[j]);
				}
			}
			else {
				stk1.push(ipt[j]);
			}
		}
		if (stk1.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
		while (!stk1.empty()) stk1.pop();
	}
}