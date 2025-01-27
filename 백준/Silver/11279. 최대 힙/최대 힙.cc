#include<bits/stdc++.h>

using namespace std;

int N, ipt;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	while (N--) {
		cin >> ipt;
		if (ipt) pq.push(ipt);
		else {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}

	return 0;
}