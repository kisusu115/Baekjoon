#include<iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int N;
	cin >> N;

	while (N--) {
		int ipt;
		cin >> ipt;
		pq.push(ipt);
	}
	if (N == 1) {
		cout << pq.top();
		return 0;
	}
	int sum = 0;
	while (pq.size() > 1) {
		int first = pq.top(); pq.pop();
		int second = pq.top(); pq.pop();
		int newdeck = first + second;
		sum += newdeck;
		pq.push(newdeck);
	}
		
	cout << sum;
	return 0;
}