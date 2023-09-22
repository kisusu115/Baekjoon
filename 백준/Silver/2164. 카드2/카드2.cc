#include<iostream>
#include<deque>

using namespace std;

int main() {
	int n;
	cin >> n;
	deque<int> deq;

	for (int i = 1; i <= n; i++) {
		deq.push_back(i);
	}
	while(deq.size()>1) {
		deq.pop_front();
		if (deq.size() > 1) {
			deq.push_back(deq.front());
			deq.pop_front();
		}
	}

	cout << deq.front();
}