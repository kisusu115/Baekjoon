#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	string ipt;
	queue<int> que;
	for (int i = 0; i < n; i++) {
		cin >> ipt;
		if (ipt == "push") {
			int ipt2;
			cin >> ipt2;
			que.push(ipt2);
		}
		else if (ipt == "pop") {
			if (que.empty()) cout << -1 << endl;
			else {
				cout << que.front() << endl;
				que.pop();
			}

		}
		else if (ipt == "size") {
			cout << que.size() << endl;
		}
		else if (ipt == "empty") {
			cout << que.empty() << endl;
		}
		else if (ipt == "front") {
			if (que.empty()) cout << -1 << endl;
			else {
				cout << que.front() << endl;
			}
		}
		else if (ipt == "back") {
			if (que.empty()) cout << -1 << endl;
			else {
				cout << que.back() << endl;
			}
		}
	}
}