#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<int> stk;

	int sum = 0;
	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int ipt;
		cin >> ipt;
		if (ipt == 0) {
			if(!stk.empty()) stk.pop();
		}
		else {
			stk.push(ipt);
		}
	}

	while (!stk.empty()) {
		sum += stk.top();
		stk.pop();
	}

	cout << sum;
}