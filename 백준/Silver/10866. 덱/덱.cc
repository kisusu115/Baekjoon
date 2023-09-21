#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int main() {
	int n;
	cin >> n;
	string ipt;
	deque<int> deq;
	for (int i = 0; i < n; i++) {
		cin >> ipt;
		if (ipt == "push_front") {
			int ipt2;
			cin >> ipt2;
			deq.push_front(ipt2);
		}
		else if (ipt == "push_back") {
			int ipt2;
			cin >> ipt2;
			deq.push_back(ipt2);
		}
		else if (ipt == "pop_front") {
			if (deq.empty()) cout << -1 << endl;
			else {
				cout << deq.front() << endl;
				deq.pop_front();
			}
		}
		else if (ipt == "pop_back") {
			if (deq.empty()) cout << -1 << endl;
			else {
				cout << deq.back() << endl;
				deq.pop_back();
			}
		}
		else if (ipt == "size") {
			cout << deq.size() << endl;
		}
		else if (ipt == "empty") {
			cout << deq.empty() << endl;
		}
		else if (ipt == "front") {
			if (deq.empty()) cout << -1 << endl;
			else {
				cout << deq.front() << endl;
			}
		}
		else if (ipt == "back") {
			if (deq.empty()) cout << -1 << endl;
			else {
				cout << deq.back() << endl;
			}
		}
	}
}