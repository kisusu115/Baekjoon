#include<bits/stdc++.h>

using namespace std;
queue<int> q;
vector<int> ret;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ipt, N, K; 
	cin >> N >> K;
	for (int i = 1; i <= N; i++) q.push(i);

	int cnt = 1;
	while (!q.empty()) {
		int f = q.front();
		q.pop();

		if (cnt % K != 0) q.push(f);
		else ret.push_back(f);
		cnt++;
	}

	cout << "<" << ret[0];
	for (int i = 1; i < ret.size(); i++) cout << ", " << ret[i];
	cout << ">";

	return 0;
}