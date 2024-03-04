#include<iostream>
#include<deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	deque<int> deq;

	for (int i = 0; i < N; i++) {
		int ipt1, ipt2;
		cin >> ipt1;
		if (ipt1 == 1) {
			cin >> ipt2;
			deq.push_front(ipt2);
		}
		else if(ipt1 == 2) {
			cin >> ipt2;
			deq.push_back(ipt2);
		}
		else if (ipt1 == 3) {
			if(deq.size()!=0){
				cout << deq.front() << "\n";
				deq.pop_front();
			}
			else cout << -1 << "\n";
		}
		else if (ipt1 == 4) {
			if (deq.size() != 0) {
				cout << deq.back() << "\n";
				deq.pop_back();
			}
			else cout << -1 << "\n";
		}
		else if (ipt1 == 5) {
			cout << deq.size() << "\n";
		}
		else if (ipt1 == 6) {
			deq.size() == 0 ? cout << 1 << "\n" : cout << 0 << "\n";
		}
		else if (ipt1 == 7) {
			if (deq.size() != 0) cout << deq.front() << "\n";
			else cout << -1 << "\n";
		}
		else if (ipt1 == 8) {
			if (deq.size() != 0) cout << deq.back() << "\n";
			else cout << -1 << "\n";
		}
	}

	return 0;
}