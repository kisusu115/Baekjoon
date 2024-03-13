#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
	vector<int> iptVect;
	vector<int> retVect;
	stack<int> numStack;
	stack<int> indexStack;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int ipt;
		cin >> ipt;

		iptVect.push_back(ipt);
		retVect.push_back(-1);
	}

	for (int i = 0; i < N; i++) {
		if (numStack.empty()) {
			numStack.push(iptVect[i]);
			indexStack.push(i);
		}
		else {
			while (!numStack.empty() && numStack.top() < iptVect[i]) {
				retVect[indexStack.top()] = iptVect[i];
				numStack.pop();
				indexStack.pop();
			}
			numStack.push(iptVect[i]);
			indexStack.push(i);
		}
	}
	cout << retVect[0];
	for (int i = 1; i < N; i++) {
		cout << " " << retVect[i];
	}
}