#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	string ipt;
	stack<int> stk;
	for (int i = 0; i < n; i++) {
		cin >> ipt;
		if (ipt == "push") {
			int ipt2;
			cin >> ipt2;
			stk.push(ipt2);
		}
		else if (ipt == "pop") {
			if (stk.empty()) cout << -1 << endl;
			else {
				cout << stk.top() << endl;
				stk.pop();
			}
			
		}
		else if (ipt == "size") {
			cout << stk.size() << endl;
		}
		else if (ipt == "empty") {
			cout << stk.empty() << endl;
		}
		else if (ipt == "top") {
			if (stk.empty()) cout << -1 << endl;
			else {
				cout << stk.top() << endl;
			}
		}
	}
}